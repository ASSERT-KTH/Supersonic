#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int R[n];
  for (int i = 0; i < n; i++)
    std::cin >> R[i];
  int maxv = R[1] - R[0];
  int minv = R[0];
  for (int i = 1; i < n; i++) {
    if (R[i] - minv > maxv)
      maxv = R[i] - minv;
    if (R[i] < minv)
      minv = R[i];
  }
  std::cout << maxv << std::endl;
  return 0;
}