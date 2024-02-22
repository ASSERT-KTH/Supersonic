#include <iostream>

int main() {
  unsigned long long a = 1;
  int n;
  std::cin >> n;
  for (int i = 2; i <= n; ++i) {
    a *= i;
  }
  std::cout << a << '\n';
  return 0;
}