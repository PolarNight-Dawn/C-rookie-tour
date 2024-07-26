//
// Created by polarnight on 24-6-5, 下午9:13.
//

#include <iostream>
#include <thread>

static bool s_finished = false;

/* 工作函数 */
void DoWork() {
  /* 一个命名空间，其中定义了与时间有关的字面量操作符 */
  using namespace std::literals::chrono_literals;

  std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

  while (!s_finished) {
	std::cout << "Working..." << std::endl;
	std::this_thread::sleep_for(1s);
  }
}

int main() {
  std::thread worker(DoWork);

  std::cin.get();

  s_finished = true;

  /* 阻塞当前主线程，直到工作线程结束 */
  worker.join();
  std::cout << "Finished!" << std::endl;
  std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

  std::cin.get();
}