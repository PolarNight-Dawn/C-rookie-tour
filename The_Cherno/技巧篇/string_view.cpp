//
// Created by polarnight on 24-7-11, 上午11:17.
//

#include <iostream>
#include <chrono>

#include "generate_tool_library.h"

static uint32_t s_alloc_count = 0;

void *operator new(size_t size) {
  s_alloc_count++;
//   std::cout << "Allocating " << size << "bytes\n";
  return malloc(size);
}

void PrintNameView(std::string_view string) {
//   std::cout << string << "\n";
}

void PrintName(const std::string &string) {
//   std::cout << string << "\n";
}

int main() {
  {
	std::cout << "String View:\n";
	GTL::Timer timer;
	int loop = 10000;
	while (loop--) {
// 	  std::string name = "Dawn123456789012 PolarNight1234567890";
// 	  std::string_view first_name(name.c_str(), 16);
// 	  std::string_view last_name(name.c_str() + 17, 19);

	  const char *name_new = "Dawn123456789012 PolarNight1234567890";

	  std::string_view first_name(name_new, 16);
	  std::string_view last_name(name_new + 17, 19);

	  PrintNameView(first_name);
	  PrintNameView(last_name);
	  PrintNameView("temp Dawn123456789012 PolarNight1234567890");
	}
	std::cout << s_alloc_count << " allocations\n";
  }

  {
	std::cout << "String:\n";
	GTL::Timer timer;
	int loop = 10000;
	s_alloc_count = 0;
	while (loop--) {
	  std::string name = "Dawn123456789012 PolarNight1234567890";
	  std::string first_name = name.substr(0, 16);
	  std::string last_name = name.substr(17, 20);
	  PrintName(first_name);
	  PrintName(last_name);
	  PrintName("temp Dawn123456789012 PolarNight1234567890");
	}
	std::cout << s_alloc_count << " allocations\n";
  }

  std::cin.get();
}