#ifndef PIXED_UTILS_SEMAPHORE_HPP
#define PIXED_UTILS_SEMAPHORE_HPP

#include <atomic>

namespace engine
{

class Semaphore
{
public:
    Semaphore(int limit);

    Semaphore(const Semaphore&) = delete;
    Semaphore(Semaphore&&) = delete;

    void acquire(int count = 1);
    void release(int count = 1);

private:
    const int limit;
    std::atomic<int> counter;
};

}

#endif // PIXED_UTILS_SEMAPHORE_HPP
