#include <iostream>

int main() {
  short x; // Use a smaller data type if the input is within a certain range
  std::cin >> x;
  
  int y = x * x * x; // Calculate the cube using a single multiplication
  
  std::cout << y << "\n";
  
  return 0;
}