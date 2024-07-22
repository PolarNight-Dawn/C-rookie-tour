//
// Created by polarnight on 24-7-13, 下午5:04.
//

#include <iostream>

class Random {
 public:
  Random(const Random &) = delete;
  Random &operator=(const Random &) = delete;

  static Random &Get() {
	static Random instance;
	return instance;
  }

  static float GenerateRandomFloat() { return Get().IGenerateRandomFloat(); }
 private:
  Random() {}

  float IGenerateRandomFloat() const { return m_random_float_; }

  float m_random_float_{0.05f};
};

int main() {
  float random_num = Random::GenerateRandomFloat();

  std::cout << random_num << "\n";
  std::cin.get();
}