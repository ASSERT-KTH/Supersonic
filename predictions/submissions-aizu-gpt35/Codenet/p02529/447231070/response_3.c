#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, d = 0;
  scanf("%d", &b);
  int *c = (int*)calloc(b + 1, sizeof(int));
  for (a = 0; a < b; a++) {
    int x;
    scanf("%d", &x);
    c[x] = 1;
  }
  for (a = 0; a < b; a++) {
    int x;
    scanf("%d", &x);
    d += c[x];
  }
  printf("%d\n", d);
  free(c);
  return 0;
}