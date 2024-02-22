#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);

  int min = 2000000;
  int t;

  std::vector<int> A(10001, 0);

  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    A[t]++;
    if (t < min)
      min = t;
  }

  A[min]--;

  printf("%d", min);

  for (int i = min; i < A.size(); i++) {
    for (int j = 0; j < A[i]; j++) {
      printf(" %d", i);
    }
  }

  printf("\n");

  return 0;
}