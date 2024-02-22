#include <stdio.h>

int main() {
  int a, b;
  scanf_s("%d %d", &a, &b);
  printf_s("%d %d\n", a * b, (a + b) * 2);
}