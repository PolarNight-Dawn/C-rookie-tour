//
// Created by polarnight on 24-6-25, 下午9:56.
//

#include <iostream>

class Entity {
 public:
  virtual void Print() {
	std::cout << "Entity\n";
  }

  void PrintEntity() {
	std::cout << "Parent Class Entity\n";
  }
};

class Player : public Entity {
 public:
  void Print() {
	std::cout << "Player\n";
  }

  void PrintEntity() {
	std::cout << "Son Class Player\n";
  }
};

class Enemy : public Entity {
 public:
  void Print() {
	std::cout << "Enemy\n";
  }

  void PrintEntity() {
	std::cout << "Son Class Enemy\n";
  }
};

int main() {
  Player *player = new Player();
  Entity *actually_enemy = new Enemy();

  Entity *actually_player = player;

  Player *p0 = dynamic_cast<Player *>(actually_enemy);

  Player *p1 = dynamic_cast<Player *>(actually_player);

  std::cin.get();
}