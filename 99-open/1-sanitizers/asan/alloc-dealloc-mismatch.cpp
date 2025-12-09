#include <iostream>

int main() {
    int* a = new int[10];
    std::fill(a, a+10, 15);
    delete a;

    std::cout << a[2] << std::endl;
    return 0;
}