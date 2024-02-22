#include <iostream>
#include <functional>

int main() {
  int a, b;
  std::cin >> a >> b;

  if (std::greater<int>()(a, b))
    std::cout << "a > b\n";
  else if (std::less<int>()(a, b))
    std::cout << "a < b\n";
  else
    std::cout << "a == b\n";

  return 0;
}