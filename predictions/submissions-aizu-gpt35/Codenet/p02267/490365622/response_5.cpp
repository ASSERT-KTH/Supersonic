#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000
#define MAX_Q 500

int main() {
  int n, *S, q, *T, i, j, cnt = 0;
  scanf("%d", &n);
  S = (int*) malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  T = (int*) malloc(q * sizeof(int));
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  for (i = 0; i < q; i++)
    for (j = 0; j < n; j++)
      if (T[i] == S[j]) {
        cnt++;
        break;
      }
  printf("%d\n", cnt);
  free(S);
  free(T);
  return 0;
}