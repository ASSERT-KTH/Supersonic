#include <cstdio>

int main() {
  int N, K, i, j, S[100], B, a;
  while (scanf("%d %d", &N, &K) != EOF, N || K) {
    for (i = K; i--;)
      scanf("%d", &S[i]);
    a = 1;
    for (i = 0; i < N && a; ++i)
      for (j = K; j--;)
        scanf("%d", &B), S[j] -= B, a = S[j] >= 0;
    printf(a ? "Yes\n" : "No\n");
  }
  return 0;
}