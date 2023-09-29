#include <stdio.h>

int main() {
  int i, k, n, q, t, C = 0, S[100], T[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  // Sorting the arrays for faster search
  for (i = 0; i < n - 1; i++) {
    for (k = i + 1; k < n; k++) {
      if (S[i] > S[k]) {
        t = S[i];
        S[i] = S[k];
        S[k] = t;
      }
    }
  }
  for (i = 0; i < q; i++) {
    // Binary search for faster search
    int l = 0, r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (S[m] == T[i]) {
        C++;
        break;
      }
      if (S[m] < T[i]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  printf("%d\n", C);
  return 0;
}