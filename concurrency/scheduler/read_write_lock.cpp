#include <iostream>
#include <thread>
#include <mutex>
/*
 An RW lock allows concurrent access for read-only operations, while write
 operations require exclusive access. This means that multiple threads can
 read the data in parallel but an exclusive lock is needed for writing or
 modifying data. When a writer is writing the data, all other writers or
 readers will be blocked until the writer is finished writing.
*/
class RWLock
{

    // >= 0  -- Read operation is being performed
    // 0 - Read or Write operation can be performed
    // -1 -- Write operation is being performed
    int32_t _status; // type of operations?


    int32_t _waiting_readers; // number of readers waiting
    int32_t _waiting_writers; // number of writers waiting

    std::mutex _mtx;
    std::condition_variable _read_cv;
    std::condition_variable _write_cv;

public:
    RWLock() : _status(0), _waiting_readers(0), _waiting_writers(0) {}
    RWLock(const RWLock&) = delete;
    RWLock(const RWLock&&) = delete;
    RWLock& operator=(const RWLock&) = delete;
    RWLock& operator=(RWLock&&) = delete;

    void read_lock()
    {
        std::unique_lock<std::mutex> lock(_mtx);
        _waiting_readers += 1;
        _read_cv.wait(lock, [&]() {
            return _waiting_writers == 0 && _status >= 0; });
        _waiting_readers -= 1;
        _status += 1;
    }

    void write_lock()
    {
        std::unique_lock<std::mutex> lock(_mtx);
        _waiting_writers += 1;
        _write_cv.wait(lock, [&](){
            return _status == 0;
        };);
        _waiting_writers -= 1;
        _status = -1;
    }

    void unlock()
    {
        std::unique_lock<std::mutex> lock(_mtx);
        if (_status == -1) // write operation
        {
            _status = 0;
        }
        else
        {
            _status -= 1;
        }

        // Notify waiting readers/writer threads about
        // this unlock operation so that they can continue
        // execution.
        if (_waiting_writers > 0) {
            if (_status == 0) {
                _write_cv.notify_one(); // there can be a single writer thread.
            }
        } else {
            _read_cv.notify_all(); // multiple readers could be blocked, notify all.
        }
    }
};
