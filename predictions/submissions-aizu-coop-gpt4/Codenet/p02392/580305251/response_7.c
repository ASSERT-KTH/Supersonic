#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c;
  if (scanf("%d %d %d", &a, &b, &c) != 3) {
    fprintf(stderr, "Error: Invalid input\n");
    return 1;
  }
  printf("%s\n", (a < b && b < c) ? "Yes" : "No");
  return 0;
}