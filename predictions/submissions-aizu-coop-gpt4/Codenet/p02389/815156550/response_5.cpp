#include <iostream>
int main() {
  int a;
  int b;
  std::cin >> a >> b;
  int product = a * b;
  std::cout << product << " " << (product + a + b) << std::endl;
}