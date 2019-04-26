#pragma once
#ifndef WORKER_H
#define WORKER_H

#include <condition_variable>
#include <mutex>

#include "abstract_request.h"

class Worker
{
    std::condition_variable cv;
    std::mutex mtx;
    std::unique_lock<std::mutex> ulock;
    AbstractRequest *request;
    bool running;
    bool ready;

public:
    Worker() : ulock(mtx),running(true), ready(false) {}
    void run();
    void stop() { running = false; }
    void setRequest(AbstractRequest *request)
    {
        this->request = request;
        ready = true;
    }
    void getCondition(std::condition_variable *&cv);
};

#endif