#include <iostream>

extern void Log(const char *message);

enum Level : unsigned char {
    level_error = 0, level_warning, level_info,
};

int main() {
    const int val = 8;
    int *ptr = (int *) &val;
    *ptr = 10;

    int **pptr = &ptr;

    std::cout << &val << std::endl;
    std::cout << ptr << " " << *ptr << std::endl;

    Level value = level_info;

    if (value == level_info)
        Log("hello, world?");

    const char *name1 = "Polar";
    char name2[6] = {'P', 'o', 'l', 'a', 'r', 0};
    std::cout << name1 << " " << name2 << std::endl;

    std::string name3 = "Polar";
    std::cout << name3 << std::endl;

    std::cin.get();
}
