#include <stdio.h>

int main(void) {
  int x;
  scanf("%d", &x);
  int cube = x * x;
  cube *= x;
  printf("%d\n", cube);
  return 0;
}