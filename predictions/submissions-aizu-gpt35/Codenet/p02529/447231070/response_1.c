#include <stdio.h>
#include <stdlib.h>
#define s scanf("%d", &b)

int a, b, d = 0, *c;

int main() {
  s;
  a = b;
  c = (int*) calloc(b+1, sizeof(int));
  
  for (; a--; c[b] = 1)
    s;
  
  for (a = b; a--; d += c[b])
    s;
  
  printf("%d\n", d);
  free(c);
  return 0;
}