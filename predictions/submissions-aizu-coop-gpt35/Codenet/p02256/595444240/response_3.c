#include <stdio.h>

int main() {
  int c = 1;

  // Read input and validate
  int a, b;
  if (scanf("%d%d", &a, &b) != 2) {
    printf("Invalid input\n");
    return 1;
  }

  // Calculate GCD
  c = a % b;
  do {
    a = b;
    b = c;
    c = a % b;
  } while (c > 0);

  // Output GCD
  printf("%d\n", a);

  return 0;
}