#include <iostream>
using namespace std;
int main() {
  int N, K, i, j, *S, B, a;
  while (a = 1, scanf("%d%d", &N, &K), N || K) {
    S = new int[K];
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i)
      for (j = K; j--;)
        scanf("%d", &B), S[j] -= B, S[j] < 0 ? a = 0 : 0;
    printf("%s\n", (a ? "Yes" : "No"));
  }
}
