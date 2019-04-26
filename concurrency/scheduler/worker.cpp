#include "worker.h"
#include "dispatcher.h"
#include <chrono>

void Worker::getCondition(std::condition_variable *&cv)
{
    cv = &(this)->cv;
}

void Worker::run()
{
    while (running)
    {
        if (ready)
        {
            ready = false;
            request->process();
            request->finish();
        }

        if (Dispatcher::addWorker(this))
        {
            // use while loop to avoid spurious wakeups.
            while (!ready && running)
            {
                if (cv.wait_for(ulock, std::chrono::seconds(1)) == std::cv_status::timeout)
                {
                    // keep waiting until there is a request in a _requests queue.
                }
            }
        }
    }
}
