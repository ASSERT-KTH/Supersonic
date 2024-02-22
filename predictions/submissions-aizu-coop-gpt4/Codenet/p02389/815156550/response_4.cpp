#include <iostream>
int main() {
  int a, b; // Initialize variables on the same line
  std::cin >> a >> b;

  int product = a * b; // Calculate product once and store it

  std::cout << product << " " << (product << 1) - (a + b) << std::endl; // Reuse product and use bit shift for doubling
}