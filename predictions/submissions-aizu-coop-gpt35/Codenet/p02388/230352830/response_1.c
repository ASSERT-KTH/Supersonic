#include <stdio.h>

int main(void) {
  int x;

  // Read the input integer
  scanf("%d", &x);

  // Calculate the cube
  int cube = x * x * x;

  // Print the result
  printf("%d\n", cube);

  return 0;
}