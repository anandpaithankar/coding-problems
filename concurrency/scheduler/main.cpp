#include <iostream>
#include <string>
#include <csignal>
#include <thread>

#include "dispatcher.h"
#include "request.h"

std::mutex loggerMutex;

void logFunc(const std::string &text)
{
    loggerMutex.lock();
    std::cout << text << "\n";
    loggerMutex.unlock();
}

int main()
{
    Dispatcher::init(10);
    Request *request = nullptr;
    int cycles = 0;
    while (cycles < 100)
    {
        request = new Request();
        request->setValue(cycles);
        request->setOutput(logFunc);
        Dispatcher::addRequest(request);
        cycles++;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    Dispatcher::stop();
    std::cout << "Complete. \n";
}