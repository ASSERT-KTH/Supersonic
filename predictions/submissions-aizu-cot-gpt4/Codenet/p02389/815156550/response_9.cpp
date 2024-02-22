#include <iostream>
int main() {
  int a;
  int b;
  std::cin >> a >> b;
  int product = a * b; // calculate the product once and store it
  std::cout << product << " " << 2 * (a + b) << std::endl; // use the product and calculate the perimeter
}