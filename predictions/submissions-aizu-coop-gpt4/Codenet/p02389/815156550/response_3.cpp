#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);  // Disable synchronization with stdio
  std::cin.tie(NULL);  // Untie cin from cout

  int a;
  int b;
  std::cin >> a >> b;

  int mult = a * b;  // Store the result of a * b first
  std::cout << mult << " " << (a + b) * 2 << std::endl;  // Combine 'std::cout' operations into one

  return 0;
}