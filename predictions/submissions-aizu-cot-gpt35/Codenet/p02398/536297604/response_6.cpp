#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);

  int a, b, s, t = 0;
  std::cin >> a >> b;
  
  for (s = a; s <= b; ++s) {
    if (b % s == 0) {
      ++t;
    }
  }
  
  std::cout << t << std::endl;
  return 0;
}