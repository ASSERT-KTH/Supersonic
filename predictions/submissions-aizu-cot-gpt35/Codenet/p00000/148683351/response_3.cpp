#include <iostream>

int main() {
    int i = 1;
    while (i <= 9) {
        for (int j = 1; j <= 9; j++) {
            int result = i * j;
            std::cout << i << "x" << j << "=" << result << '\n';
        }
        i++;
    }

    return 0;
}