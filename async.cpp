//
// Created by polarnight on 24-7-8, 下午9:13.
//

#include <iostream>
#include <chrono>
#include <future>
#include <vector>
#include <mutex>

class Timer {
 public:
  Timer() {
	m_start_time_point_ = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
	stop();
  }

  void stop() {
	auto end_time_point = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_time_point_).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();

	auto duration = end - start;
	auto ms = duration * 0.001;

	std::cout << duration << "us (" << ms << "ms)\n";
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time_point_;
};

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
	Timer timer;
	long result = 0;
	worker(start, end, result);
	std::cout << "Sync:\n";
  }

  {
	Timer timer;

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