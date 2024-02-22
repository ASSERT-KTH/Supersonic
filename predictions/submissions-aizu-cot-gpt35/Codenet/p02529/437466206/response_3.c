#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int main() {
  int i, n, q, C = 0, S[MAX], T[MAX];
  bool exists[MAX] = {false}; // initialize hash set
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
    exists[S[i]] = true; // add element to hash set
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if (exists[T[i]]) { // check if element exists in hash set
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}