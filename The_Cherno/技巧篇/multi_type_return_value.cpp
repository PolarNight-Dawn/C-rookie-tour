//
// Created by polarnight on 24-7-22, 下午4:12.
//

#include <iostream>
#include <functional>

enum kPersonIndex {
  xiao_ming = 0,
  xiao_hong = 1,
  xiao_li = 2
};

struct PersonIndex {
  std::string sex;
  int age;
};

template<typename T>
T GetPersonInfo(int person_type);

/* 通过函数调用的参数返回多类型
 * 不太推荐，因为会产生额外的开销，并且你懂得，这样函数签名会显得比较臃肿复杂 */
void GetPersonInfo(int person_type, std::string &sex, int &age) {
  switch (person_type) {
	case xiao_ming: sex = "男", age = 20;
	  break;
	case xiao_hong: sex = "女", age = 18;
	  break;
	case xiao_li: sex = "男", age = 17;
	  break;
	default: sex = "null", age = 0;
	  break;
  }
}

/* std::pair 同理，只是返回值替换成 make_pair() 而已
 * std::tuple 和 std::pair 都不能清晰地表明返回值的变量名，具体可跳至 main 函数中该函数的调用 */
template<>
std::tuple<std::string, int> GetPersonInfo<std::tuple<std::string, int>>(int person_type) {
  switch (person_type) {
	case xiao_ming: return std::make_tuple("男", 20);
	case xiao_hong: return std::make_tuple("女", 18);
	case xiao_li: return std::make_tuple("男", 17);
	default: return std::make_tuple("null", 0);
  }
}

/* 推荐的方法 */
template<>
PersonIndex GetPersonInfo<PersonIndex>(int person_type) {
  switch (person_type) {
	case xiao_ming: return {"男", 20};
	case xiao_hong: return {"女", 18};
	case xiao_li: return {"男", 17};
	default: return {"null", 0};
  }
}

int main() {
  std::string sex;
  int age;
  GetPersonInfo(xiao_hong, sex, age);
  std::cout << sex << " " << age << " argument\n";

  auto person_info = GetPersonInfo<std::tuple<std::string, int>>(xiao_li);
  std::cout << std::get<0>(person_info) << " " << std::get<1>(person_info) << " tuple\n";

  auto person_info_struct = GetPersonInfo<PersonIndex>(xiao_ming);
  std::cout << person_info_struct.sex << " " << person_info_struct.age << " struct\n";

  std::cin.get();
}
