//
// Created by polarnight on 24-6-5, 下午10:34.
//

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

class Timer {
public:
    std::chrono::time_point<std::chrono::system_clock> begin, end;
    std::chrono::duration<float> duration = end - begin;

    Timer() {
        begin = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - begin;
        auto time = duration.count() * 1000.0f;
        std::cout << "Timer took " << time << "ms\n";
    }
};

void Function() {
    Timer timer;

    for (int i = 0; i < 10; i++)
        std::cout << "Hello World! " << i << "\n";
}

int main() {
    Function();

    std::cin.get();
}
