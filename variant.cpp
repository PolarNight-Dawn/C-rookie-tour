//
// Created by polarnight on 24-7-7, 下午8:42.
//

#include <iostream>
#include <variant>
#include <fstream>

enum class kErrorCode {
  none = 0,
  not_found = 1,
  not_access = 2
};

std::variant<std::string, kErrorCode> ReadFileAsString(const std::string &file_path) {
  std::ifstream file(file_path);

  if (!file) {
	if (!std::ifstream(file_path).good()) {
	  return kErrorCode::not_found;
	}
	return kErrorCode::not_access;
  }

  std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  file.close();

  return content;
}

int main() {
  auto data = ReadFileAsString("example.txt");
//   std::cout << std::get<std::string>(data) << "\n";
  std::string *str = std::get_if<std::string>(&data);
  if (auto value = std::get_if<kErrorCode>(&data)) {
	kErrorCode &error = *value;
	switch (error) {
	  case kErrorCode::not_found: std::cout << "Error: File not found.\n";
		break;
	  case kErrorCode::not_access: std::cout << "Error: No access to file.\n";
		break;
	}
  }

  std::cout << sizeof(std::string) << "\n";
  std::cout << sizeof(kErrorCode) << "\n";
  std::cout << sizeof(data) << "\n";

  union test {
	std::string string_;
	kErrorCode k_error_code_;
  };

  std::cout << sizeof(test) << "\n";

  std::cin.get();
}