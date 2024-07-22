//
// Created by polarnight on 24-5-26, 下午5:34.
//

#include <cstring>
#include <iostream>

class String {
private:
    char *m_buffer_;
    unsigned int m_size_;

public:
    String(const char *string) {
        m_size_ = strlen(string);
        m_buffer_ = new char[m_size_];
        memcpy(m_buffer_, string, m_size_);
    }

    // String(const String &other) = delete;
    String(const String &other) : m_size_(other.m_size_) {
        std::cout << "string copied!" << std::endl;
        m_buffer_ = new char[m_size_ + 1];
        memcpy(m_buffer_, other.m_buffer_, m_size_ + 1);
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &string);

    char& operator[](unsigned int index) {
        return m_buffer_[index];
    }

    ~String() {
        delete[] m_buffer_;
    }
};

std::ostream &operator<<(std::ostream &stream, const String &string) {
    stream << string.m_buffer_;
    return stream;
}

void PrintString(const String& string) {
    std::cout << string << std::endl;
}

int main() {
    String string = "cherno";
    PrintString(string);

    String second = string;
    second[2] = 'a';
    PrintString(second);

    std::cin.get();
}