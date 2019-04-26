#pragma once
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <vector>
#include <queue>
#include <thread>

#include "worker.h"

class Dispatcher
{
    static std::queue<AbstractRequest *> _requests;
    static std::queue<Worker *> _workers;
    static std::mutex _requestsMutex;
    static std::mutex _workerMutex;
    static std::vector<Worker *> _allWorkers;
    static std::vector<std::thread *> _threads;

public:
    static bool init(int workers);
    static bool stop();
    static void addRequest(AbstractRequest *request);
    static bool addWorker(Worker *worker);
};

#endif