//
// Created by polarnight on 24-6-11, 下午10:51.
//

#include <iostream>

struct Entity {
    int x, y;

    int* GetPositions() {
        return &x;
    }
};

int main() {
    Entity e = {5, 8};

    int y = *(int *) ((int *) &e + 1);

    int* positions = e.GetPositions();
    positions[0] = 6;

    std::cout << positions[0] << " " << y << "\n";

    std::cin.get();
}