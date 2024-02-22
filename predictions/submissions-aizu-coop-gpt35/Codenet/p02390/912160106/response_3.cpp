#include <iostream>

int main() {
  int is;
  std::cin >> is;

  int h = is / 3600;
  int m = (is % 3600) / 60;
  int s = is % 60;

  std::cout << h << ":" << m << ":" << s << std::endl;
  return 0;
}