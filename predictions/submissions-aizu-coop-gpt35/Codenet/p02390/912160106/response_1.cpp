#include <iostream>

int main() {
    int seconds;
    std::cin >> seconds;

    int hours = seconds / 3600;
    seconds %= 3600;  // Remaining seconds after calculating hours

    int minutes = seconds / 60;
    seconds %= 60;  // Remaining seconds after calculating minutes

    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

    return 0;
}