#include <iostream>

int main() {
  int S;
  std::cin >> S;
  int hours = S / 3600;
  S %= 3600;
  int minutes = S / 60;
  int seconds = S % 60;
  std::cout << hours << ":" << minutes << ":" << seconds << "\n";
  return 0;
}