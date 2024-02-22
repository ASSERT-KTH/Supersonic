#include <cstdio>
const int MAX_K = 1000; // Replace 1000 with maximum possible K
int main() {
  int N, K, i, j, S[MAX_K], B, a;
  while (scanf("%d %d", &N, &K), N || K) {
    a = 1;
    for (i = 0; i < K; ++i)
      scanf("%d", &S[i]);
    for (i = 0; i < N; ++i)
      for (j = 0; j < K; ++j) {
        scanf("%d", &B);
        S[j] -= B;
      }
    for (j = 0; j < K; ++j)
      if (S[j] < 0) {
        a = 0;
        break;
      }
    printf("%s\n", (a ? "Yes" : "No"));
  }
  return 0;
}