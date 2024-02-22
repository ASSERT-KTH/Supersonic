#include <iostream>

int main() {
  int S;
  std::cin >> S;

  int hours = S / 3600;
  int minutes = (S / 60) % 60;
  int seconds = S % 60;

  std::cout << std::setfill('0') << std::setw(2) << hours << ":"
            << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds << std::endl;

  return 0;
}