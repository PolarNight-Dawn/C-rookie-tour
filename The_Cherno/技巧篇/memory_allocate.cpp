//
// Created by polarnight on 24-7-27, 上午10:03.
//

#include <iostream>
#include <memory>

struct AllocationMetrics {
  uint32_t total_allocated = 0;
  uint32_t total_freed = 0;

  uint32_t CurrentUsage() { return total_allocated - total_freed; }
};

static AllocationMetrics allocation_metrics;

void *operator new(size_t size) {
  allocation_metrics.total_allocated += size;

  return malloc(size);
}

void operator delete(void *memory, size_t size) {
  allocation_metrics.total_freed += size;

  free(memory);
}

struct Object{
  int x, y, z;
};

static void PrintMemoryUsage() {
  std::cout << "Memory Usage: " << allocation_metrics.CurrentUsage() << " bytes\n";
}

int main() {
  PrintMemoryUsage();
  std::string str = "Hello, world? I'm Dawn Polarnight!";
  PrintMemoryUsage();
  {
	std::unique_ptr<Object> obj = std::make_unique<Object>();
	PrintMemoryUsage();
  }
  PrintMemoryUsage();

  std::cin.get();
}