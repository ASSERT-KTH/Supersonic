#include <stdio.h>
int main() {
  int a, b, c = 1;
  scanf("%d%d", &a, &b);
  while (c > 0) {
    c = a % b, a = b, b = c;
  }
  printf("%d\n", a);
}
