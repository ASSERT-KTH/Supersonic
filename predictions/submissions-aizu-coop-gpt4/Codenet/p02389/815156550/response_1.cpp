#include <iostream>

int main() {
  int a;
  int b;
  std::cin >> a >> b;
  
  int double_a = a * 2;
  int double_b = b * 2;
  
  std::cout << a * b << " " << double_a + double_b << std::endl;
}