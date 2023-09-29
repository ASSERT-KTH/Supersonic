#include <stdio.h>
#include <stdlib.h>
#define s(x) scanf("%d", &x)

int main() {
  int a, b, d = 0;
  s(b);
  int *c = (int*)calloc(b+1, sizeof(int));
  
  for (a = 0; a < b; a++) {
    int x;
    s(x);
    c[x] = 1;
  }

  for (a = 0; a < b; a++) {
    int x;
    s(x);
    d += c[x];
  }

  printf("%d\n", d);
  free(c);
  return 0;
}