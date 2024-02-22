#include <stdio.h>

int main() {
  int a, b, c;

  // Input the numbers
  scanf("%d%d", &a, &b);

  // Calculate the GCD
  do {
    c = a % b;
    a = b;
    b = c;
  } while (c > 0);

  // Output the GCD
  printf("%d\n", a);

  return 0;
}