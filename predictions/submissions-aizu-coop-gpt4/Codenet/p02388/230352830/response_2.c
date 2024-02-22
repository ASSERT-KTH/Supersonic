#include <stdio.h>

int main(void) {
  int x, cube;
  scanf("%d", &x);
  
  // Calculate the cube of x
  cube = x;
  cube *= x * x;  // Use multiplication assignment operator
  
  printf("%d\n", cube);
  return 0;
}