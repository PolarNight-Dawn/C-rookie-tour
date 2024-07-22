//
// Created by polarnight on 24-5-22, 下午9:10.
//

#include <iostream>
#include <memory>

class Entity {
private:
    const char* m_name_;
    int m_age_;
    int m_x_, m_y_;
public:
    Entity() {
        std::cout << "Create Entity" << std::endl;
    }

    explicit Entity(const char* name) : m_name_(name), m_age_(-1) {}

    explicit Entity(int age) : m_name_("Unknown"), m_age_(age) {}

    Entity(int x, int y) {
        Entity *e = this;
        this->m_x_ = x;
        (*this).m_y_ = y;
    }

    ~Entity() {
        std::cout << "Delete Entity" << std::endl;
    }
};

int main() {
    Entity a("dawn");
    Entity *a2 = new Entity(3);
    // Entity a1 = "dawn";
    Entity b(21);
    // Entity b1 = 21;

    // std::unique_ptr<Entity> entity(new Entity());
    // std::unique_ptr<Entity> entity1 = new Entity();
    // std::unique_ptr<Entity> entity3 = std::make_unique<Entity>();


    {
        std::shared_ptr<Entity> e0;
        std::weak_ptr<Entity> weak_entity;
        {
            std::shared_ptr<Entity> share_entity = std::make_shared<Entity>();
            weak_entity = share_entity;
            share_entity = e0;
        }
    }

    std::cin.get();

}