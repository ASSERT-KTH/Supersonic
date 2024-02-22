#include <iostream>
int main() {
  int is;
  int h, m;
  std::cin >> is;
  h = is / 3600;
  m = (is % 3600) / 60;
  is = is % 60;
  std::cout << h << ":" << m << ":" << is << std::endl;
  return 0;
}