#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int* R = new int[n];
  for (int i = 0; i < n; i++)
    std::cin >> R[i];

  int maxv = R[1] - R[0];
  int minv = R[0];
  for (int i = 1; i < n; i++) {
    int diff = R[i] - minv;
    if (diff > maxv)
      maxv = diff;
    if (R[i] < minv)
      minv = R[i];
  }

  std::cout << maxv << std::endl;

  delete[] R;
  return 0;
}