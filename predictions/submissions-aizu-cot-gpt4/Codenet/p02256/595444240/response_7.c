#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d%d", &a, &b);
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  printf("%d\n", a);
  return 0;
}