//
// Created by polarnight on 24-7-8, 下午9:13.
//

#include <iostream>
#include <chrono>
#include <future>
#include <vector>
#include <mutex>

#include "generate_tool_library.h"

static std::mutex s_mutex;

void worker(long start, long end, long &shared_sum) {
  int sum = 0;
  for (int i = start; i < end; ++i)
	sum += i;

  //! \std::lock_gurd 一个 RAII 风格的锁管理器，在其作用范围内自动加锁并在退出范围时自动解锁
  std::lock_guard<std::mutex> lock(s_mutex);
  shared_sum += sum;
}

int main() {
  long start = 1, end = 2000000000;

  {
	gtl::Timer timer;
	long result = 0;
	worker(start, end, result);
	std::cout << "Sync:\n";
  }

  {
	gtl::Timer timer;

	int num_threads = std::thread::hardware_concurrency();
	std::vector<std::future<void>> futures;
	long range = (end - start) / num_threads;
	long shared_sum = 0;

	for (int i = 0; i < num_threads; i++) {
	  long range_start = start + i * range;
	  long range_end = (i == num_threads - 1) ? end : (range_start + range);
	  //! \std::async 不能传入非常量左值引用，如果需要传递的话，需要手动明晰可能的安全问题，使用 std::ref 包装后即可传递
	  futures.push_back(std::async(std::launch::async, worker, range_start, range_end, std::ref(shared_sum)));
	}
	std::cout << "Async:\n";
  }

  std::cin.get();
}