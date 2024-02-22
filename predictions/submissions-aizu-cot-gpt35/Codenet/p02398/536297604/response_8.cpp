#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  int t = 0;
  for (int s = a; s <= b; s++) {
    if (c % s == 0) {
      t++;
    }
  }

  std::cout << t << std::endl;
  return 0;
}