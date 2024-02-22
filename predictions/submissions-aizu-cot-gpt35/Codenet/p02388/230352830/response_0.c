#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x = atoi(argv[1]);
  x *= x * x;
  printf("%d\n", x);
  return 0;
}