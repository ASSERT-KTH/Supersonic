#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int S;
    std::cin >> S;

    int hours = S / 3600;
    int minutes = (S % 3600) / 60;
    int seconds = S % 60;

    std::cout << hours << ":" << minutes << ":" << seconds << "\n";

    return 0;
}