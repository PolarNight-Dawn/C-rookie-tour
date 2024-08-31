//
// Created by polarnight on 24-8-29, 下午3:33.
//

#include <iostream>

template<typename T>
class NameObject {
 public:
  NameObject(std::string &name, const T &value) : name_value(name), object_value(value) {}

  NameObject &operator=(const NameObject &other) {
	if (this != &other) {
	  // 手动赋值 name_value 引用指向的对象
	  name_value = other.name_value;
	  // object_value 是 const，无法赋值，因此不能重新赋值
	  const_cast<T &>(object_value) = other.object_value;
	}
	return *this;
  }

  std::string &name_value;
  const T object_value;
};

int main() {
  std::string new_str("a");
  std::string old_str("b");
  NameObject<int> p(new_str, 2);
  NameObject<int> s(old_str, 36);
  p = s;

  std::string s1("a");
  std::string s2("b");
  std::string &s1_ref = s1;
  std::string &s2_ref = s2;
  s1_ref = s2_ref;

  std::cout << p.name_value << std::endl;
  std::cout << s1_ref << std::endl;

  return 0;
}
