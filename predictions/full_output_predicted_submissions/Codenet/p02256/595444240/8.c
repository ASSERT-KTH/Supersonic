#include <stdio.h>
int main() {
  int a, b, c = 1, i;
  scanf("%d%d", &a, &b);
  while (a > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  printf("%d\n", c);
}
