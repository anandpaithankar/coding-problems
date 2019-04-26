#include "dispatcher.h"
#include <iostream>

std::queue<AbstractRequest *> Dispatcher::_requests;
std::queue<Worker *> Dispatcher::_workers;
std::mutex Dispatcher::_requestsMutex;
std::mutex Dispatcher::_workerMutex;
std::vector<Worker *> Dispatcher::_allWorkers;
std::vector<std::thread *> Dispatcher::_threads;

bool Dispatcher::init(int numWorkers)
{
    std::thread *t = nullptr;
    Worker *w = nullptr;
    for (int i = 0; i < numWorkers; i++)
    {
        w = new Worker;
        _allWorkers.push_back(w);
        t = new std::thread(&Worker::run, w); // run method from instance of a class 'w'
        _threads.push_back(t);
    }
    return true;
}

bool Dispatcher::stop()
{
    for (int i = 0; i < _allWorkers.size(); i++)
    {
        _allWorkers[i]->stop();
    }

    for (int i = 0; i < _threads.size(); i++)
    {
        _threads[i]->join();
    }
    return true;
}

void Dispatcher::addRequest(AbstractRequest *request)
{
    _workerMutex.lock();
    //std::cout << "Dispatch:addRequest:: Worker queue size " << _workers.size() << "\n";
    if (!_workers.empty())
    {
        Worker *worker = _workers.front();
        worker->setRequest(request);
        std::condition_variable *cv;
        worker->getCondition(cv);
        cv->notify_one();
        _workers.pop();
        _workerMutex.unlock();
    }
    else
    {
        _workerMutex.unlock();
        _requestsMutex.lock();
        //std::cout << "Dispatch::addRequest: Pushing a request in a requests queue.\n";
        _requests.push(request);
        _requestsMutex.unlock();
    }
}

bool Dispatcher::addWorker(Worker *worker)
{
    bool wait = true;
    _requestsMutex.lock();
    if (!_requests.empty())
    {
        AbstractRequest *request = _requests.front();
        worker->setRequest(request);
        _requests.pop();
        wait = false;
        _requestsMutex.unlock();
    }
    else
    {
        _requestsMutex.unlock();
        _workerMutex.lock();
        _workers.push(worker);
        _workerMutex.unlock();
    }

    return wait;
}
