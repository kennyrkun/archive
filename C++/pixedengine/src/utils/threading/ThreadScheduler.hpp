#ifndef PIXED_UTILS_THREADSCHEDULER_HPP
#define PIXED_UTILS_THREADSCHEDULER_HPP

#include <queue>
#include <thread>
#include <mutex>
#include <type_traits>
#include <functional>

namespace engine
{

class ThreadScheduler
{
public:

    ///  Schedules execution of functor with
    template<typename Callable, typename... Args>
    void schedule(Callable functor, Args&&... args)
    {
        std::lock_guard<std::mutex> lock(queueAccessMutex);
        jobsQueue.push([functor, &args...]() {
            functor(args...);
        });
    }

    ThreadScheduler() = default;

    ///  ThreadScheduler d-tor.
    ///  Stops all reserved threads. Jobs left in queue will not be executed.
    ~ThreadScheduler();

    // In theory, it's possible to make multiply ThreadSchedulers
    // share single pool of threads, but it's bad idea.
    ThreadScheduler(const ThreadScheduler&) = delete;

    ///  Moves scheduled jobs from 'other' instance. Threads will not be moved.
    ///  After this c-tor call, 'other' will have no threads and empty jobs queue.
    ThreadScheduler(ThreadScheduler&& other);

    ///  Adds X threads to pool. They will be used instantly.
    void reserveThreads(unsigned count);

    ///  Stops all reserved threads. Jobs left in queue will not be executed.
    void releaseThreads();
private:
    static void threadEntry(ThreadScheduler& controller);

    std::queue<std::function<void()> > jobsQueue;
    std::mutex queueAccessMutex;

    bool termination = false;

    std::vector<std::thread> threads;
};

}

#endif // PIXED_UTILS_THREADSCHEDULER_HPP
