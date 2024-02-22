#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c;
  
  // Error checking for scanf
  if (scanf("%d %d %d", &a, &b, &c) != 3) {
      printf("Error in input\n");
      return(EXIT_FAILURE);
  }

  // Use of ternary operator for cleaner code
  printf((a < b && b < c) ? "Yes\n" : "No\n");
  
  return (0);
}