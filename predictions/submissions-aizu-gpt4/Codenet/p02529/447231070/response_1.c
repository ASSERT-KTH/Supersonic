#include <stdio.h>
#define s(n) scanf("%d", &n)

int main() {
  int a, b, d = 0;
  int c[1000] = {0};

  s(a);
  while(a--) {
    s(b);
    c[b] = 1;
  }

  s(a);
  while(a--) {
    s(b);
    d += c[b];
  }

  printf("%d\n", d);
  return 0;
}