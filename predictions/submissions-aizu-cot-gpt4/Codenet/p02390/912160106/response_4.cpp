#include <iostream>

int main() {
  int sec;
  int h, m, s;
  std::cin >> sec;
  h = sec / 3600;
  m = (sec % 3600) / 60;
  s = sec % 60;
  std::cout << h << ":" << m << ":" << s << std::endl;
  return 0;
}