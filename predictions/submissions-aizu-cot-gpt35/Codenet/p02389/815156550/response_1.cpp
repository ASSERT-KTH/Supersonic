#include <iostream>
#include <ostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  
  int product = a * b;
  int sum = a * 2 + b * 2;
  
  std::cout << product << " " << sum << std::endl;
}