//
// Created by polarnight on 24-6-27, 下午9:14.
//

#include <iostream>
#include <tuple>

std::tuple<std::string, int> CreatePerson() {
  return {"Dawn", 21};
}

int main() {
  // 处理一
  auto person = CreatePerson();
  auto name = std::get<0>(person);
  auto age = std::get<1>(person);

  // 处理二
  std::string name_tie;
  int age_tie;
  std::tie(name_tie, age_tie) = CreatePerson();

  // 处理三
  auto [name_auto, age_auto] = CreatePerson();

  std::cin.get();
}