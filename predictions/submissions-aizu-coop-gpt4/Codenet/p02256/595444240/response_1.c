#include <stdio.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  while (b != 0) {
    int remainder = a % b;
    a = b;
    b = remainder;
  }
  printf("%d\n", a);
  return 0;
}