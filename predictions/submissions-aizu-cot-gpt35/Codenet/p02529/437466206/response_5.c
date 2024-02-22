#include <stdio.h>

#define MAX_SIZE 100

int main() {
  int i, n, q, t, C = 0, S[MAX_SIZE], T[MAX_SIZE];
  int hashSet[MAX_SIZE] = {0}; // Initialize hash set with 0

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
    hashSet[S[i]] = 1; // Set corresponding element in hash set to 1
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if (hashSet[T[i]]) { // Check if element exists in hash set
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}