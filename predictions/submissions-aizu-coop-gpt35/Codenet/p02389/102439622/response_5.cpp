#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int result = a * b; // Calculate area and perimeter in one step
  printf("%d %d\n", result, (a + b) * 2);
}