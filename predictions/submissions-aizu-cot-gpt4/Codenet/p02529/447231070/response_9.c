#include <stdio.h>

char c[999];
int a, b, d;

int main() {
  for (scanf("%d", &b), a = b; a--; c[b] = 1)
    scanf("%d", &b);
  for (scanf("%d", &b), a = b; a--; d += c[b])
    scanf("%d", &b);
  printf("%d\n", d);
  return 0;
}