#include <stdio.h>

int main(void) {
  int x;
  scanf("%d", &x);
  
  int cube = x * x * x;  // Compute the cube of x
  
  printf("%d\n", cube);  // Print the result
  return 0;
}