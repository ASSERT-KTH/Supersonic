#include <stdio.h>
int main() {
  register int a, b; 
  scanf("%d %d", &a, &b);
  printf("%d %d\n", a * b, a * 2 + b * 2); // Directly print area and perimeter
}