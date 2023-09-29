#include <stdio.h>
#include <string.h>

int main() {
  int a, b, d = 0;
  int c[999];
  memset(c, 0, sizeof(c));

  scanf("%d", &a);
  while(a--) {
    scanf("%d", &b);
    c[b] = 1;
  }

  scanf("%d", &a);
  while(a--) {
    scanf("%d", &b);
    d += c[b];
  }

  printf("%d\n", d);
  return 0;
}