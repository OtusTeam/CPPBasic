#include <unordered_map>
#include <iostream>
#include <thread>

std::unordered_map<int, int> _ma;


int assign101() {
    for (int idx = 0; idx < 100; idx++) _ma[idx] = 101;
    return 0;
}

int assign102() {
    for (int idx = 0; idx < 100; idx++) _ma[idx] = 102;
    return 0;
}

int main() {
    std::thread x1(assign101);
    std::thread x2(assign102);

    x1.join();
    x2.join();

    std::cout << _ma[5] << std::endl;
}
