#include <stdio.h>

int main() {
  int a, b, d = 0;
  int c[1000] = {0};

  scanf("%d", &a);
  for (int i = 0; i < a; ++i) {
    scanf("%d", &b);
    c[b] = 1;
  }

  scanf("%d", &a);
  for (int i = 0; i < a; ++i) {
    scanf("%d", &b);
    d += c[b];
  }

  printf("%d\n", d);
  return 0;
}