#include <stdio.h>
#define s scanf("%d", &b)

int main() {
  int a, b, d = 0;
  int c[100000] = {0};
  for (s, a = b; a--; c[b]++)
    s;
  for (s, a = b; a--; d += c[b])
    s;
  printf("%d\n", d);
  return 0;
}