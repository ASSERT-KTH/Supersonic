#include <stdio.h>

int main() {
  int a, b, c;
  
  // Step 1: Use separate scanf calls for each integer
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  
  // Step 2: Store the result in a variable instead of printing immediately
  char* result;
  if (a < b && b < c) {
    result = "Yes";
  } else {
    result = "No";
  }
  
  // Step 3: Print the result once at the end
  printf("%s\n", result);
  
  return 0;
}