#include <iostream>
#include <bitset>

int main() {
    std::bitset<30> data;
    int n;
    for (int i = 0; i < 28; i++) {
        std::cin >> n;
        data.set(n - 1);
    }
    for (int i = 1; i <= 30; i++) {
        if (!data.test(i - 1))
            std::cout << i << std::endl;
    }
}