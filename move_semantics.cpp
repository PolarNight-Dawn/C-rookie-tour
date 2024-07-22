//
// Created by polarnight on 24-7-17, 下午5:30.
//

#include <iostream>
#include <cstring>

class String {
 public:
  String() : m_data_(nullptr), m_size_(0) {};

  String(const char *string) {
	printf("Created\n");
	m_size_ = strlen(string);
	m_data_ = new char[m_size_];
	memcpy(m_data_, string, m_size_);
  }

  String(const String &other) {
	printf("Copyed\n");
	m_size_ = other.m_size_;
	m_data_ = new char[m_size_];
	memcpy(m_data_, other.m_data_, m_size_);
  }

  String(String &&other) noexcept {
	printf("Moved\n");
	m_size_ = other.m_size_;
	m_data_ = other.m_data_;

	other.m_size_ = 0;
	other.m_data_ = nullptr;
  }

  String &operator=(String &&other) noexcept {
	printf("Moved\n");

	if (this != &other) {
	  delete[] m_data_;
	  m_size_ = other.m_size_;
	  m_data_ = other.m_data_;

	  other.m_size_ = 0;
	  other.m_data_ = nullptr;
	}

	return *this;
  }

  ~String() {
	printf("Destroyed\n");
	delete[] m_data_;
  }

  void Print() {
	for (uint32_t i = 0; i < m_size_; i++)
	  printf("%c", m_data_[i]);

	printf("\n");
  }
 private:
  char *m_data_;
  uint32_t m_size_;
};

class Entity {
 public:
  Entity(const String &name) : m_name_(name) {}

  Entity(String &&name) : m_name_(std::move(name)) {}

  void PrintName() {
	m_name_.Print();
  }
 private:
  String m_name_;
};

int main() {
  {
	Entity entity("Dawn");
	entity.PrintName();

	String str = "hello";
	String dest = std::move(str);
  }

  {
	String apple = "Apple";
	String dest;

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	dest = std::move(apple);

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();
  }

  std::cin.get();
}