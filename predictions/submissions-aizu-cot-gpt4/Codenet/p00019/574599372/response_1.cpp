#include <cstdio>
#include <iostream>

int main() {
  long long a = 1;
  long long n;
  std::cin >> n;
  for (long long i = 2; i <= n; ++i) {
    a *= i;
  }
  std::cout << a << std::endl;
  return 0;
}