#include <stdio.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  while (b != 0) { // Change loop condition to stop when b is zero
    int c = a % b;
    a = b;
    b = c;
  }
  printf("%d\n", a);
}