#include <stdio.h>

#define MAX_PARENS 1000  // Define the maximum number of parentheses that printf can handle at a time
#define NUM_PARENS 110000  // Define the total number of parentheses to be printed

int main() {
  int a[4];
  char parens[MAX_PARENS + 1];  // +1 for the null-terminating character
  memset(parens, '(', MAX_PARENS);  // Fill the array with parentheses
  parens[MAX_PARENS] = '\0';  // Add a null-terminating character at the end

  while (1) {
    if (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]) != 4) {
      break;  // Break if less than 4 numbers were read
    }
    if (a[0] == 0) {
      break;
    }
    for (int i = 0; i < NUM_PARENS / MAX_PARENS; ++i) {
      printf("%s", parens);  // Print MAX_PARENS parentheses at a time
    }
    for (int i = 0; i < NUM_PARENS % MAX_PARENS; ++i) {
      putchar('(');  // Print the remaining parentheses one by one
    }
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
  return 0;
}