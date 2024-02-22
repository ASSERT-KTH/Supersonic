#include <bitset>
#include <iostream>

int main() {
    std::bitset<31> data; // initialize all bits to 0
    int n;
    for (int i = 0; i < 28; i++) {
        std::cin >> n;
        data.set(n); // mark number as seen
    }
    for (int i = 1; i <= 30; i++) {
        if (!data.test(i)) // if number i is not seen
            std::cout << i << std::endl;
    }
}