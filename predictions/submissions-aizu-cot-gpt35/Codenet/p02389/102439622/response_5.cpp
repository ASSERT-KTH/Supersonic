#include <stdio.h>

int main() {
  int a, b;
  scanf_s("%d %d", &a, &b);
  
  int c = a * 2 + b * 2;
  printf_s("%d %d\n", a * b, c);
}