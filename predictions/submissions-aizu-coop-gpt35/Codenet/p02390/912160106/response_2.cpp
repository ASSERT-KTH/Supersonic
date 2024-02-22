#include <iostream>

int main() {
    int seconds;
    std::cout << "Enter the number of seconds: ";
    std::cin >> seconds;

    if (seconds < 0) {
        std::cout << "Invalid input! Please enter a positive integer." << std::endl;
        return 0;
    }

    int hours = seconds / 3600;
    seconds %= 3600;

    int minutes = seconds / 60;
    seconds %= 60;

    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

    return 0;
}