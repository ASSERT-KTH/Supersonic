#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b;

  // Input validation
  if (scanf("%d %d", &a, &b) != 2) {
    printf("Invalid input\n");
    return 1;
  }

  int area = a * b;
  int perimeter = (a + b) * 2;

  // Print the calculated values
  printf("%d %d\n", area, perimeter);

  return 0;
}