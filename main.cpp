#include "accumulate.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    v.shrink_to_fit();
    std::cout << accumulate(v.begin(),v.end(), 40);
    return 0;
}
