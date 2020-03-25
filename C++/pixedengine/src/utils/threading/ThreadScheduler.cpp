#include "ThreadScheduler.hpp"
#include <iostream>
#include <utility>

pixed::ThreadScheduler::~ThreadScheduler()
{
    this->releaseThreads();
}

pixed::ThreadScheduler::ThreadScheduler(pixed::ThreadScheduler&& other)
{
    std::lock_guard<std::mutex> lock1(other.queueAccessMutex);
    std::lock_guard<std::mutex> lock2(this->queueAccessMutex);

    this->jobsQueue = std::move(other.jobsQueue);

    unsigned threadsCount = other.threads.size();
    other.releaseThreads();
    this->reserveThreads(threadsCount);
}

void pixed::ThreadScheduler::reserveThreads(unsigned count)
{
    while (count --> 0)
        threads.push_back(std::thread(threadEntry, std::ref(*this)));
}

void pixed::ThreadScheduler::releaseThreads()
{
    this->termination = true;
    for (std::thread& thread : threads)
        thread.join();
}

void pixed::ThreadScheduler::threadEntry(pixed::ThreadScheduler& controller)
{
    while (!controller.termination) {
        while (!controller.jobsQueue.empty()) {
            controller.queueAccessMutex.lock();
            auto functor = controller.jobsQueue.front();
            controller.jobsQueue.pop();
            controller.queueAccessMutex.unlock();

            functor();
        }
    }
}
