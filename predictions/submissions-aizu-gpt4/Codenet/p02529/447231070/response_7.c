#include <stdio.h>
#define s scanf("%d", &b)
int a, b, d, c[999] = {0};
int main() {
  for (scanf("%d", &a); a--;)
  {
    scanf("%d", &b);
    c[b] = 1;
  }
  for (scanf("%d", &a); a--;)
  {
    scanf("%d", &b);
    d += c[b];
  }
  printf("%d\n", d);
  return 0;
}