#pragma once
#include <iterator>
#include <thread>
#include <vector>
#include <numeric>
#include <iostream>
#include <mutex>
#include <cmath>

std::mutex m;

template <typename Iterator, typename Type>
Type parallelAccumulate(Iterator begin, Iterator end, Type initialValue)
{
    auto size = std::distance(begin,end);
    if(!size) return initialValue;

    auto hardwareThreads = std::thread::hardware_concurrency() != 0 ? std::thread::hardware_concurrency() : 2;
    std::vector<Type> partialSum;
    int blockSize = floor(static_cast<double>(size) / static_cast<double>(hardwareThreads));
    std::vector<std::thread> threads;
    Iterator blockEnd = begin;

    for(int i = 0; i < hardwareThreads-1; ++i)
    {
        threads.emplace_back(std::thread([&](){
            m.lock();
            blockEnd += blockSize;
            partialSum.push_back(std::accumulate(begin,blockEnd,0));
            begin += blockSize;
            m.unlock();
        }));

    }
    threads.emplace_back(std::thread([&](){
        partialSum.push_back(std::accumulate(begin,end,0));
    }));

    for(auto && t : threads)
    {
        t.join();
    }

    return std::accumulate(partialSum.begin(),partialSum.end(), initialValue);
}
