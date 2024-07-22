//
// Created by polarnight on 24-3-24, 下午11:44.
//

#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int *ptr = &x;

    cout << x << endl << *ptr << endl << ptr << endl << &x << endl;

    cout << "---------------------------------" << endl;

    *ptr = 20;

    cout << &ptr << endl << ptr << endl << *ptr << endl;

    return 0;
}