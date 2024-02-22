#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, *S, q, *T, i, j, cnt = 0;
  scanf("%d", &n);
  S = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for S
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  T = (int*)malloc(q * sizeof(int)); // Dynamically allocate memory for T
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  
  // Rest of the code remains the same
  // ...
  
  free(S); // Free dynamically allocated memory for S
  free(T); // Free dynamically allocated memory for T
  return 0;
}