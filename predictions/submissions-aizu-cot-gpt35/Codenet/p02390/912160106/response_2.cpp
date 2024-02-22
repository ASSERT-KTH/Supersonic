#include <iostream>

int main() {
  int input;
  std::cin >> input;

  int hours = input / 3600;
  int minutes = (input % 3600) / 60;
  int seconds = (input % 3600) % 60;

  std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
  return 0;
}