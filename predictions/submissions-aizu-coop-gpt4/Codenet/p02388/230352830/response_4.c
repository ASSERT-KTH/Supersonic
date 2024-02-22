#include <stdio.h>

int main(void) {
  int x;
  if (scanf("%d", &x) != 1) {
    fprintf(stderr, "Error: Invalid input\n");
    return 1;
  }
  
  int square = x * x;
  printf("%d\n", square * x);
  
  return 0;
}