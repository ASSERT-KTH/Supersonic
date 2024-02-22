#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false); // Disable synchronization with C standard library

    int S;
    std::cin >> S;

    int hours = S / 3600;
    int minutes = (S % 3600) / 60;
    int seconds = S % 60;

    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

    return 0;
}