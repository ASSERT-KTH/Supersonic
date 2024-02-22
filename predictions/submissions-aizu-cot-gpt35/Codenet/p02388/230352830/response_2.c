#include <stdio.h>

int main(void) {
  int num;
  scanf("%d", &num);
  
  // Input validation
  if (num < INT_MIN || num > INT_MAX) {
    printf("Invalid input\n");
    return 0;
  }
  
  // Store the result of x * x * x in a variable
  long long result = (long long)num * num * num;
  
  // Print the result
  printf("%lld\n", result);
  
  return 0;
}