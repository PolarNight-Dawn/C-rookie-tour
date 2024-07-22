//
// Created by polarnight on 24-6-3, 下午10:54.
//

#include <iostream>]
#include <vector>

void HelloWorld(int x) {
    std::cout << x << " ,Hello World?" << std::endl;
};

void Output(const std::vector<int> &values, void(*haven)(int)) {
    for (auto value: values)
        haven(value);
}

int main() {
    std::vector<int> values = {9, 5, 2, 7};

    Output(values, HelloWorld);
     std::cin.get();
}
