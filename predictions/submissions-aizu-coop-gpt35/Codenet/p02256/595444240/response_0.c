#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  
  // Calculate GCD using modulo operator
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  
  printf("%d\n", a);
}