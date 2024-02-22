#include <iostream>

int main() {
  const double pai = 3.141592653589;
  int a, b;
  std::cin >> a >> b;

  if (a > b)
    std::cout << "a > b\n";
  else if (a < b)
    std::cout << "a < b\n";
  else
    std::cout << "a == b\n";

  return 0;
}