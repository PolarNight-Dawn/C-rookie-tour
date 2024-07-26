//
// Created by polarnight on 24-7-26, 下午8:26.
//

#ifndef C____GENERATE_TOOL_LIBRARY_H_
#define C____GENERATE_TOOL_LIBRARY_H_

#include <iostream>
#include <chrono>

namespace generate_tool_library {
class Timer {
 public:
  Timer() {
	m_start_timer_point_ = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
	Stop();
  }

  void Stop() {
	auto end_timer_point = std::chrono::high_resolution_clock::now();

	auto start_time =
		std::chrono::time_point_cast<std::chrono::microseconds>(m_start_timer_point_).time_since_epoch().count();
	auto end_time = std::chrono::time_point_cast<std::chrono::microseconds>(end_timer_point).time_since_epoch().count();

	auto duration = end_time - start_time;
	auto ms = duration * 0.001f;

	std::cout << duration << " us(" << ms << " ms)\n";

  }
 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timer_point_;
};
}

namespace GTL = generate_tool_library;

#endif //C____GENERATE_TOOL_LIBRARY_H_
