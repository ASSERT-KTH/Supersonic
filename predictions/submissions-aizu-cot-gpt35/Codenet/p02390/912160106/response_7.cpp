#include <iostream>

int main() {
  int input_seconds;
  int hours, minutes, seconds;
  std::cin >> input_seconds;
  
  hours = input_seconds / 3600;
  input_seconds = input_seconds % 3600;
  
  minutes = input_seconds / 60;
  seconds = input_seconds % 60;
  
  std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
  return 0;
}