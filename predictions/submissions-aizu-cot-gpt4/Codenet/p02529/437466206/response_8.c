#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, k, n, q, C = 0;
  scanf("%d", &n);
  int *S = (int*) malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  int *T = (int*) malloc(q * sizeof(int));
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  int hash[1000000] = {0};
  for (i = 0; i < n; i++) {
    hash[S[i]]++;
  }
  for (k = 0; k < q; k++) {
    if (hash[T[k]] > 0) {
      C++;
    }
  }
  printf("%d\n", C);
  free(S);
  free(T);
  return 0;
}