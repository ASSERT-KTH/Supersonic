#include <iostream>

int main() {
  int totalSeconds, remainingSeconds;
  int h, m, s;
  
  std::cin >> totalSeconds;
  
  h = totalSeconds / 3600;
  remainingSeconds = totalSeconds % 3600;
  
  m = remainingSeconds / 60;
  s = remainingSeconds % 60;
  
  std::cout << h << ":" << m << ":" << s << std::endl;
  
  return 0;
}