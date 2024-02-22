#include <stdio.h>
int a, b, d, c[100];
int main() {
  scanf("%d", &b);
  for (a = b; a--; c[b] = 1) {
    scanf("%d", &b);
  }
  for (a = b; a--; d += c[b]) {
    scanf("%d", &b);
  }
  printf("%d\n", d);
  return 0;
}