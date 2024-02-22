#include <iostream>

int main() {
    int S;
    std::cin >> S;
    int remainder = S % 3600;
    std::cout << S / 3600 << ':' << remainder / 60 << ':' << remainder % 60 << '\n';
    return 0;
}