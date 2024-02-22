#include <stdio.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (b != 0) {
    int c;
    do {
      c = a % b;
      a = b;
      b = c;
    } while (b != 0);
  }
  printf("%d\n", a);
  return 0;
}