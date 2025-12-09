#include <iostream>
#include <thread>

int x = 0;


int increase100() {
    for (int idx = 0; idx < 100; idx++) x = x + 1;
    return 0;
}

int main() {

    std::thread x1(increase100);
    std::thread x2(increase100);

    x1.join();
    x2.join();

    std::cout << x << std::endl;
}
