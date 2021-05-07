#include <iostream>
#include <queue>
#include "Queue.h"
#include <stack>

#define WITH_STD

int main()
{
#ifdef WITH_STD
    std::queue<int, int> a;
#else
    none_std::queue a;
#endif // WITH_STD

    

    //std::queue<int, int> a;
    //std::stack<int, int> b;
  
}