#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int n, *S, q, *T, i, j, cnt = 0;
  scanf("%d", &n);
  S = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  qsort(S, n, sizeof(int), compare);
  scanf("%d", &q);
  T = (int*)malloc(q * sizeof(int));
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  for (i = 0; i < q; i++)
    if (bsearch(&T[i], S, n, sizeof(int), compare)) {
      cnt++;
    }
  printf("%d\n", cnt);
  free(S);
  free(T);
  return 0;
}