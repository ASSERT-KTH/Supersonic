#include <stdio.h>

int main() {
  int a, b, c;

  // Take user input
  scanf("%d%d%d", &a, &b, &c);

  // Check if the inputs are in increasing order and print the result
  printf("%s\n", (a < b && b < c) ? "Yes" : "No");

  return 0;
}