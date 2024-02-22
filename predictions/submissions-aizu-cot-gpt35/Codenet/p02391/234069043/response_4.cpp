#include <iostream>

int main() {
  float pai = 3.141592653589f;
  int a, b;
  std::cin >> a >> b;
  
  if (a > b)
    std::cout << "a > b" << std::endl;
  else if (a < b)
    std::cout << "a < b" << std::endl;
  else
    std::cout << "a == b" << std::endl;
  
  return 0;
}