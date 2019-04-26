#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mx;
std::queue<int> q;
std::atomic<bool> finished;
std::condition_variable cv;

void reader()
{
    std::cout << "Reader: Begin \n";
    std::unique_lock<std::mutex> lock(mx);
    cv.wait(lock, [&](){return !q.empty() || finished;});
    while(!q.empty())
    {
        std::cout << "Consumer: " << q.front() << "\n";
        q.pop();
    }
}

void writer()
{
    std::cout << "Writer: Begin \n";
    std::unique_lock<std::mutex> lock(mx);
    while(!finished)
    {
        for (int i = 0; i < 10; i++) {
            q.push(i);
        }
        //std::cout << "Notify reader \n";
        cv.notify_all();
    }
}


int main()
{
    finished = false;

    std::cout << "Main thread \n";
    std::thread w(writer);
    std::thread r(reader);

   std::this_thread::sleep_for(std::chrono::milliseconds(50));
   finished = true;


    w.join();
    r.join();
    std::cout << "Main thread: Complete \n";
}