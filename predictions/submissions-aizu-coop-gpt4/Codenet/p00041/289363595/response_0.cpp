#include <stdio.h>
#include <string.h>

int main() {
  int a[4];
  // Create a string with 1000 opening brackets
  char brackets[1001];
  memset(brackets, '(', 1000);
  brackets[1000] = '\0';  // Null-terminate the string
  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }
    // Print the brackets in chunks of 1000
    for (int i = 0; i < 110; ++i)
      printf("%s", brackets);
    printf("%d+%d+%d+%d", a[0], a[1], a[2], a[3]);
    putchar('\n');
  }
}