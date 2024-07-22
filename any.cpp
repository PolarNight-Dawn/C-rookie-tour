//
// Created by polarnight on 24-7-8, 上午10:59.
//

#include <iostream>
#include <any>

void *operator new(size_t size) {
  std::cout << size << "byte\n";
   return malloc(size);
}

int main() {
  std::any data;
  data = 2;
  data = std::string("Dawn");
  std::string &str = std::any_cast<std::string &>(data);

  std::cin.get();
}
