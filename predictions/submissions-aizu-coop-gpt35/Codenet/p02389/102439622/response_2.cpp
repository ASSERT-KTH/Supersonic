#include <stdio.h>

int main() {
  int a, b;
  fgets(input, sizeof(input), stdin);  // Read input as a string
  sscanf(input, "%d %d", &a, &b);     // Parse integers from the string

  int area = a * b;
  int perimeter = (a + b) * 2;

  printf("%d %d\n", area, perimeter);
  return 0;
}