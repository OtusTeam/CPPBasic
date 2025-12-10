#include <iostream>
#include <thread>
#include <mutex>

int x = 0;

std::mutex x1,x2,x3;

int main() {
    std::mutex m1;
    std::mutex m2;

    auto f1 = [&m1, &m2]() {
        std::cout << "in f1\n";
        std::lock_guard<std::mutex> lg1(m1);
        std::cout << "inside f1\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lg2(m2);
        std::cout << "out f1\n";
    };

    auto f2 = [&m1, &m2]() {
        std::cout << "in f2\n";
        std::lock_guard<std::mutex> lg1(m2);
        std::cout << "inside f2\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lg2(m1);
        std::cout << "out f2\n";
    };

    std::thread thread1([&f1, &f2]() {
        f1();
    });

    std::thread thread2([&f1, &f2]() {
        f2();
    });

    thread1.join();
    thread2.join();
}
