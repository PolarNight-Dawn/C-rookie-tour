//
// Created by polarnight on 24-6-24, 下午10:30.
//

#include <iostream>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            Vector2 a, b;
        };
        struct {
            float x, y, z, w;
        };
    };
};

void PrintVector2 (const Vector2& vector2) {
    std::cout << vector2.x << "," << vector2.y << "\n";
}

int main() {
    Vector4 vector4 = {1.0f, 2.0f, 3.0f, 4.0f};
    PrintVector2(vector4.a);
    PrintVector2(vector4.b);

    std::cout << "--------------------------------\n";
    vector4.z = 5.0f;
    PrintVector2(vector4.a);
    PrintVector2(vector4.b);

    std::cout << "--------------------------------\n";
    Vector2 vector2 = {6.0f, 7.0f};
    vector4.a = vector2;
    vector2.x = 8.0f;
    vector4.b = vector2;
    PrintVector2(vector4.a);
    PrintVector2(vector4.b);

    std::cin.get();
}