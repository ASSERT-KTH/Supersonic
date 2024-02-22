#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c;
  
  // Read a line of input
  char input[100];
  fgets(input, sizeof(input), stdin);
  
  // Parse the integers from the input string
  sscanf(input, "%d %d %d", &a, &b, &c);
  
  // Check if a < b < c
  printf("%s\n", (a < b && b < c) ? "Yes" : "No");
  
  return 0;
}