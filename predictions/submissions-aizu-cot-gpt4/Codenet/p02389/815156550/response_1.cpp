#include <iostream>
int main() {
  int a;
  std::cin >> a;
  int product = a;
  std::cin >> a;
  product *= a;
  std::cout << product << "\n" << a * 3 << std::endl;
}