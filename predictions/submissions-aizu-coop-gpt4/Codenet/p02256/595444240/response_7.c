#include <stdio.h>

int main() {
  int a, b, c = 1;
  scanf("%d%d", &a, &b);
  
  // Input validation
  if (a <= 0 || b <= 0) {
    printf("Error: Both inputs must be positive integers.\n");
    return 1;
  }
  
  // Loop optimization
  do {
    c = a % b;
    a = b;
    b = c;
  } while (c > 0);
  
  printf("%d\n", a);
  
  return 0;
}