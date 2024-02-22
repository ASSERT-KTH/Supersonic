#include <stdio.h>

int main(void) {
  int a, b, c;

  // Read the input values directly into the variables
  scanf("%d %d %d", &a, &b, &c);

  // Check if a, b, and c are in increasing order
  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}