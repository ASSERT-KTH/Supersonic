#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> R(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &R[i]);
  int maxv = R[1] - R[0];
  int minv = R[0];
  for (int i = 1; i < n; i++) {
    maxv = std::max(maxv, R[i] - minv);
    minv = std::min(minv, R[i]);
  }
  printf("%d\n", maxv);
  return 0;
}