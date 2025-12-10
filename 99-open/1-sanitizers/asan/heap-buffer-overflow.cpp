
#include <vector>

int main() {
    // Create a vector of size 10, but with a capacity of 20.
    std::vector<int> v(10);
    v.reserve(20);
    v[10] = 1; // not throw exception
    v[20] = 1;
}
