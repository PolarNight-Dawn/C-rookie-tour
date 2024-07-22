//
// Created by polarnight on 24-7-11, 上午11:17.
//

#include <iostream>
#include <chrono>

static uint32_t s_alloc_count = 0;

class Timer {
 public:
  Timer() {
	m_start_time_point_ = std::chrono::high_resolution_clock::now();
  }

  ~Timer() { Stop(); }

  void Stop() {
	auto end_time_point = std::chrono::high_resolution_clock::now();

	auto
		start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_time_point_).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();

	auto duration = end - start;
	auto ms = duration * 0.001;

	std::cout << duration << "us(" << ms << "ms)\n";
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time_point_;
};

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
	Timer timer;
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
	Timer timer;
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