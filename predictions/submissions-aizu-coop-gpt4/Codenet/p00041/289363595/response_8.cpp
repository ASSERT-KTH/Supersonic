#include <stdio.h>

int main() {
  int a[4];
  char parentheses[110001];  // An array to hold the parentheses
  
  // Initialize the parentheses array
  for (int i = 0; i < 110000; ++i)
      parentheses[i] = '(';
  parentheses[110000] = '\0';  // Null-terminate the string

  while (1) {
    // Read the first integer
    scanf("%d", &a[0]);
    if (a[0] == 0) {
      break;
    }

    // Read the remaining integers
    for (int i = 1; i < 4; ++i) {
      scanf("%d", &a[i]);
    }

    // Print the parentheses and the sum
    printf("%s%d+%d+%d+%d\n", parentheses, a[0], a[1], a[2], a[3]);
  }
}