#include <iostream>
#include <cstdio>

bool dfs(int d, double l, double r, double T, double P) {
  while (d > 0) {
    double mid = (l + r) / 2;
    if (mid >= T) {
      l = mid;
    } else {
      r = mid;
    }
    d--;
  }
  return (l >= T) ? P : 1.0 - P;
}

int main() {
  int K, R, L;
  double P, E, T;
  std::cin >> K >> L >> R >> P >> E >> T;
  std::printf("%.9f\n", dfs(K, L, R, T, P));
  return 0;
}