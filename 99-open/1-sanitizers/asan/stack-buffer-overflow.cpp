#include <iostream>

int main() {
    int b[16];
    int a[16];
    *(a+17)=5;

    std::cout << std::hex << &b << '\t' << &a << '\t' << (&b+17) << std::endl;
    // std::cout << b[]
    return 0;
}
