#include <stdio.h>

int main(void) {
  int a, b, c;

  // Step 1: Remove redundant variable declaration
  // int a, b, c;

  // Step 2: Remove invalid input validation
  // 0 <= a, b, c <= 100;

  scanf("%d %d %d", &a, &b, &c);

  // Step 3: Modify comparison condition
  if (a < c) {
    // Step 4: Use conditional operator in printf
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}