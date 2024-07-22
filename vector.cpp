//
// Created by polarnight on 24-5-28, 下午8:57.
//

#include <iostream>
#include <vector>

class Vertex {
 private:
  unsigned int m_x_, m_y_, m_z_;

 public:
  Vertex(unsigned int x, unsigned int y, unsigned z) : m_x_(x), m_y_(y), m_z_(z) {}

  Vertex(const Vertex &vertex) : m_x_(vertex.m_x_), m_y_(vertex.m_y_), m_z_(vertex.m_z_) {
	std::cout << "Copied!" << std::endl;
  }
};

int main() {
  {
	std::vector<Vertex> vertices;

	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));
  }

// 优化一
  {
	std::vector<Vertex> vertices;

	vertices.reserve(3);
	vertices.push_back({1, 2, 3});
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));
  }

//   优化二
  {
	std::vector<Vertex> vertices;

	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
  }

  std::cin.get();
}