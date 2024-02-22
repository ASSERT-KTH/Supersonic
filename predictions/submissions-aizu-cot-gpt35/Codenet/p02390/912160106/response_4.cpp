#include <iostream>

int main() {
  int seconds;
  std::cin >> seconds;

  int hours = seconds / 3600;
  seconds %= 3600;

  int minutes = seconds / 60;
  seconds %= 60;

  std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
  return 0;
}