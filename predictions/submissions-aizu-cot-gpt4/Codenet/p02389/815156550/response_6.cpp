#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    
    int product = a * b;
    int doubledSum = a * 2 + b * 2;
    
    std::cout << product << " " << doubledSum << "\n";
    
    return 0;
}