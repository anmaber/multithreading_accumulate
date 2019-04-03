#pragma once
#include <iterator>


template <typename Iterator, typename Type>
Type accumulate(Iterator begin, Iterator end, Type initialValue)
{
    if(std::distance(end,begin) == 0) return initialValue;

}

