//
// Created by polarnight on 24-6-27, 下午10:00.
//

#include <iostream>
#include <fstream>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string &file_path) {
  std::ifstream stream(file_path);
  if (stream) {
	std::string result;
	stream.close();
	return result;
  }

  return {};
}

int main() {
  auto data = ReadFileAsString("./data.txt");
  if (data) {
	std::cout << "file open successfully\n";
  } else {
	std::cout << "file open failure\n";
  }

  std::cin.get();
}