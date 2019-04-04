#include "accumulate.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v2(1000,2);
    std::cout<< parallelAccumulate(v2.begin(),v2.end(),900);

    return 0;
}
