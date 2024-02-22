#include <stdio.h>
int main(void) {
  int x, cube;
  scanf("%d", &x);
  cube = x * x;
  cube = cube * x;
  printf("%d\n", cube);
  return 0;
}