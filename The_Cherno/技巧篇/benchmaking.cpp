//
// Created by polarnight on 24-7-26, 下午8:14.
//

#include <iostream>
#include <array>
#include <memory>

#include "generate_tool_library.h"

struct Vector2{
  float x, y;
};

/* 在 Debug 模式下分析你会发现一些问题，这对测试性能不是很好，因为 Debug 有很多额外的安全措施，需要时间
 * 配置切换到 Release 再进行分析，一定要确保你所分析的代码，在发布时是真正有意义的，因为你不会在调试时发布代码 */
int main() {
  {
	gtl::Timer timer;

	int value = 0;

	for (int i = 0; i < 1000000; i++)
	  value += 2;

	std::cout << value << std::endl;
  }

  std::cout << "Make Shared: \n";
  {
	std::array<std::shared_ptr<Vector2>, 1000> shared_ptr;
	gtl::Timer timer;
	for (auto & i : shared_ptr)
	  i = std::make_shared<Vector2>();
  }

  std::cout << "New Shared: \n";
  {
	std::array<std::shared_ptr<Vector2>, 1000> shared_ptr;
	gtl::Timer timer;
	for (auto & i : shared_ptr)
	  i = std::shared_ptr<Vector2>(new Vector2());
  }

  std::cout << "Make Unique: \n";
  {
	std::array<std::unique_ptr<Vector2>, 1000> shared_ptr;
	gtl::Timer timer;
	for (auto & i : shared_ptr)
	  i = std::make_unique<Vector2>();
  }

  std::cin.get();
}
