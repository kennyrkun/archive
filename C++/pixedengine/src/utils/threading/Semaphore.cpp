#include "Semaphore.hpp"
#include <cassert>
#include <thread>
#include <iostream>

pixed::Semaphore::Semaphore(int limit)
    : limit(limit)
    , counter(0)
{
}

void pixed::Semaphore::acquire(int count)
{
    if (counter + count > limit) {
        while (counter + count <= limit) {}
    }
    counter += count;
}

void pixed::Semaphore::release(int count)
{
    assert(count <= counter);
    counter -= count;
}
