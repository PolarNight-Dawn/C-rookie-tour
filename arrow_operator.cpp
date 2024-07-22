//
// Created by polarnight on 24-5-26, 下午10:07.
//

#include <iostream>
#include <cstring>


struct Vector3 {
    float x, y, z;
};

class Entity {
private:
    char * m_name_;

public:
    Entity() : m_name_("dawn") {}

    void Print(const char *string) {
        std::cout << "hello " << string << std::endl;
    }
};

int main() {
    Entity entity;
    entity.Print("polar1");

    auto e = &entity;
    (*e).Print("polar2");
    e->Print("polar3");

    auto offset = (long)&((Vector3*)nullptr)->z;
    std::cout << offset << std::endl;

    std::cin.get();
}