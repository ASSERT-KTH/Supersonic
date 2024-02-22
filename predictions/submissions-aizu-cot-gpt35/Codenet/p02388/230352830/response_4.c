#include <stdio.h>

int main(void) {
  int x;
  scanf("%d", &x);
  int cube = x * x;
  printf("%d\n", cube * x);
  return 0;
}