#include <iostream>

int c[5004], d[5004], m, t, u, i;
int main() {
  std::cin >> c[0];
  for (i = 1; i < c[0]; ++i)
    std::cin >> c[i];

  int x;
  while (std::cin >> x) {
    for (u = i = t = 0; i < c[0]; t = d[i], d[i] = std::max(m, u), ++i)
      u = x - c[i] ? u : t + 1;
    if (u > m)
      m = u;
  }
  std::cout << m << std::endl;
  return 0;
}