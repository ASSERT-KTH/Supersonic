#include <stdio.h>

int main() {
  int a, b, c;

  // Read input integers
  scanf_s("%d%d%d", &a, &b, &c);

  // Check if integers are in increasing order
  if (a < b && b < c) {
    // Print "Yes" using puts
    puts("Yes");
  } else {
    // Print "No" using puts
    puts("No");
  }

  // Print a newline character
  puts("");

  return 0;
}