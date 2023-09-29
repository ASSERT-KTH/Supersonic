#include <cstdio>
#include <vector>
#include <climits>

int main() {
  int n;
  scanf("%d", &n);
  int min = INT_MAX, t;
  std::vector<int> A(10001, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  printf("%d", min);
  for (int i = min; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) { printf(" %d", i); }
  }
  printf("\n");
  return 0;
}