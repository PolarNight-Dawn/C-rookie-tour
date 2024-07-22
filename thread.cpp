//
// Created by polarnight on 24-6-5, 下午9:13.
//

#include <iostream>
#include <thread>

static bool s_finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals;

    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

    while (!s_finished) {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    std::thread worker(DoWork);

    std::cin.get();
    s_finished = true;

    worker.join();
    std::cout << "Finished!" << std::endl;
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

    std::cin.get();
}