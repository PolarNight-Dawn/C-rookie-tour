//
// Created by polarnight on 24-6-2, 下午6:36.
//

#include <iostream>

#define WAIT std::cin.get()
#define PR_DEBUG 0

// #if 0

#if PR_DEBUG == 1
#define LOG(x)
#elif defined(PR_DEBUG)
#define LOG(x)  \
std::cout << x << std::endl
#endif

// #endif

int main() {
    LOG("Hello");
    WAIT;
}