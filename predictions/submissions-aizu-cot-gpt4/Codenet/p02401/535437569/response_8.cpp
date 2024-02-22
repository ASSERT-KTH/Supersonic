#include <iostream>

int main() {
    int x, y;
    char z;

    while (std::cin >> x >> z >> y && z != '?') {
        switch(z) {
            case '+':
                std::cout << (x + y) << "\n";
                break;
            case '-':
                std::cout << (x - y) << "\n";
                break;
            case '/':
                if(y != 0) {
                    std::cout << (x / y) << "\n";
                }
                break;
            case '*':
                std::cout << (x * y) << "\n";
                break;
        }
    }

    return 0;
}