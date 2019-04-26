#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std::chrono_literals;

std::condition_variable odd_cv;
std::condition_variable even_cv;
std::condition_variable zero_cv;

std::mutex shutdown_lock;
std::mutex wait_lock;
std::mutex even_lock;
std::mutex odd_lock;

int counter = 0;
bool shutdown = false;
bool ready = false;

void PrintZero()
{
    std::unique_lock<std::mutex> lock(shutdown_lock);
    while (!shutdown)
    {
        lock.release();
        std::cout << "0";
        ++counter;
        if (counter % 2)
        {
            odd_cv.notify_all();
        }
        else
        {
            even_cv.notify_all();
        }

        std::unique_lock<std::mutex> waitLock(wait_lock);
        std::cout << "Waiting on Zero CV \n";
        zero_cv.wait(waitLock);
    }
}

void PrintEven()
{
    std::cout << "PrintEven \n";
    std::unique_lock<std::mutex> lock(shutdown_lock);
    while (!shutdown)
    {
        std::unique_lock<std::mutex> l(wait_lock);
        even_cv.wait(l);
        std::cout << counter;
        std::cout << "PrintEven:  Notify Zero thread \n";
        zero_cv.notify_one();
    }
}

void PrintOdd()
{
    std::cout << "PrintOdd \n";
    std::unique_lock<std::mutex> lock(shutdown_lock);
    while (!shutdown)
    {
        std::unique_lock<std::mutex> l(odd_lock);
        odd_cv.wait(l);
        std::cout << counter;
        std::unique_lock<std::mutex> waitLock(wait_lock);
        std::cout << "PrintOdd: Notify Zero thread \n";
        zero_cv.notify_one();
    }
}

int main()
{
    std::thread t0(PrintZero);
    std::thread t1(PrintEven);
    std::thread t2(PrintOdd);

    t0.join();
    t1.join();
    t2.join();

    std::this_thread::sleep_for(1s);

    {
        std::unique_lock<std::mutex> lock(shutdown_lock);
        shutdown = true;
    }

    return 0;
}
