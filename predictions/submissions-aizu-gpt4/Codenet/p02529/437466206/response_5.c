#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100

int main() {
  int i, n, q, C = 0;
  bool S[MAX_N] = {false}, T[MAX_N] = {false};
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int temp; 
    scanf("%d", &temp); 
    S[temp] = true;
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int temp; 
    scanf("%d", &temp); 
    T[temp] = true;
  }
  for (i = 0; i < MAX_N; i++) {
    if (S[i] && T[i]) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}