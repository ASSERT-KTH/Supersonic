#include <iostream>

int main() {
  int n;
  std::cin >> n;
  
  int cube = n * n;
  cube *= n;
  
  std::cout << cube << std::endl;
  
  return 0;
}