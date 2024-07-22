//
// Created by polarnight on 24-7-17, 下午4:05.
//

#include <iostream>

void PrintSum(int a, int b) {
  std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

int main() {
  int value = 0;
  PrintSum(++value, ++value);

  std::cin.get();
}
