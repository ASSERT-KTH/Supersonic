#include <stdio.h>
#include <stdbool.h>

int main() {
  int i, k, n, q, t, C = 0;
  scanf("%d", &n);
  int S[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  int T[q];
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  bool isPresent[1000001] = {false}; // assuming maximum value of S and T is 10^6
  for (i = 0; i < n; i++) {
    isPresent[S[i]] = true;
  }
  for (i = 0; i < q; i++) {
    if (isPresent[T[i]]) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}