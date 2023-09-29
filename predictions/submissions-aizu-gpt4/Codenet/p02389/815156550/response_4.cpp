#include <iostream>
int main() {
  int a, b;
  std::ios_base::sync_with_stdio(false); // For faster I/O
  std::cin.tie(NULL);
  std::cin >> a >> b;
  std::cout << a * b << " " << (a + b) << " " << std::endl;
}