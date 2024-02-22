#include <stdio.h>

int main() {
  int a, b, c;
  
  // Check if scanning was successful
  if(scanf("%d%d%d", &a, &b, &c) != 3) {
    printf("Invalid input!\n");
    return 1;
  }
  
  // Use ternary operator for simplicity
  printf((a < b && b < c) ? "Yes\n" : "No\n");
  
  return 0;
}