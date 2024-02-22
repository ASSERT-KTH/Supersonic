#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n, q, C = 0;
  int *S = (int*)calloc(1000, sizeof(int));  // Initialize all elements to 0
  int T[100];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    S[num]++;  // Increment the count of this number
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  for (i = 0; i < q; i++) {
    if (S[T[i]] > 0) {  // If this number was found in the first sequence
      C++;
      S[T[i]] = 0;  // Mark this number as counted
    }
  }

  printf("%d\n", C);
  free(S);  // Free the allocated memory
  return 0;
}