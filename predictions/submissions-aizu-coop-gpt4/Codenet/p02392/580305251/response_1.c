#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a = 0, b = 0, c = 0;
  
  if (scanf("%d %d %d", &a, &b, &c) != 3) {
    fprintf(stderr, "Invalid input\n");
    return EXIT_FAILURE;
  }

  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return EXIT_SUCCESS;
}