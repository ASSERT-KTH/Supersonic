#include <stdio.h>

int main(void) {
  int x;
  int cube;
  
  scanf("%d", &x);
  
  cube = x * x * x;
  
  printf("%d\n", cube);
  
  return 0;
}