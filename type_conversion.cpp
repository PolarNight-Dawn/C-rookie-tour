//
// Created by polarnight on 24-6-23, 下午5:46.
//

#include <iostream>

class Base {
 public:
  Base() {}

  virtual ~Base() {}
};

class Derived : public Base {
 public:
  Derived() {}

  ~Derived() {}
};

class Another : public Base {
 public:
  Another() {}

  ~Another() {}
};

int main() {
  double value = 5.24;
  double a = (int)value + 5.3;

  double s = static_cast<int>(value) + 5.3;

  for (int i = 0; i < 5; i++) {
	std::cout << i << std::endl;
  }

  Another another = *reinterpret_cast<Another *>(&value);

  Derived *derived = new Derived();

  Base *base = derived;

  Another *ac = dynamic_cast<Another *>(base);
  if (!ac) {
	std::cout << "Derived\n";
  } else {
	std::cout << "Another\n";
  }

  std::cin.get();
}
