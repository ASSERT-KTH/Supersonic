#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int i, n, q, C = 0, S[100], T[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  qsort(S, n, sizeof(int), compare);
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  qsort(T, q, sizeof(int), compare);
  for (i = 0; i < n; i++) {
    if (bsearch(&S[i], T, q, sizeof(int), compare)) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}