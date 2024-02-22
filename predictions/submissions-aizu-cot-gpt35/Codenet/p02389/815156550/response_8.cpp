#include <iostream>
#include <ostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  
  int doubleA = a * 2;
  int doubleB = b * 2;
  
  std::cout << a * b << " " << doubleA + doubleB << '\n';
}