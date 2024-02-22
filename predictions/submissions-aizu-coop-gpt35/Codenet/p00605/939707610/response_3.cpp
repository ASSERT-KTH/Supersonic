#include <iostream>

int main() {
  int N, K, i, j, S[10], B;  // Use a fixed-size array instead of dynamic allocation
  bool a;  // Use a boolean flag instead of int

  while (scanf("%d %d", &N, &K), N || K) {  // Use scanf for faster input
    a = true;  // Initialize the flag as true
    for (i = 0; i < K; ++i)
      scanf("%d", &S[i]);

    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        scanf("%d", &B);
        S[j] -= B;
        if (S[j] < 0) {
          a = false;
          break;
        }
      }
    }
    
    printf("%s\n", a ? "Yes" : "No");  // Use printf for faster output
  }
}