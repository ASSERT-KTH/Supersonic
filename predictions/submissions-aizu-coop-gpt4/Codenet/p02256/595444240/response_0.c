#include <stdio.h>

int main() {
  int a, b;

  scanf("%d%d", &a, &b);

  if (a <= 0 || b <= 0) {
    printf("Error: inputs must be positive integers\n");
    return 1;
  }

  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }

  printf("%d\n", a);

  return 0;
}