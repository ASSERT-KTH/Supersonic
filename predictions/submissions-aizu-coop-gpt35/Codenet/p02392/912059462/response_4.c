#include <stdio.h>

int main() {
  int a, b, c;
  
  // Input three integers
  scanf("%d%d%d", &a, &b, &c);
  
  // Check if the integers are in ascending order and print the result
  printf("%s\n", (a < b && b < c) ? "Yes" : "No");
  
  return 0;
}