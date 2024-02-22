#include <stdio.h>

#define MAX_SIZE 100

int main() {
  int i, n, q, C = 0, S[MAX_SIZE];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    for (int j = 0; j < n; j++) {
      if (S[j] == t) {
        C++;
        break;
      }
    }
  }
  printf("%d\n", C);
  return 0;
}