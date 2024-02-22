#include <stdio.h>

int main(void) {
  int x;
  int cube = 1;
  
  // No input required, directly calculate the cube
  // scanf("%d", &x);
  
  // Efficiently calculate the cube using exponentiation by squaring
  cube = x * x;
  
  // Print the cube using printf
  printf("%d\n", cube);
  
  return 0;
}