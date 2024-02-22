#include <stdio.h>

int n, t[128]; // Reduced array size to fit ASCII character set

int main() {
  int i;
  while (scanf("%d", &n) == 1) { // Check return value of scanf() directly
    for (i = 0; i < n; ++i) { // Ensure each character's value is set
      scanf(" %c", &t[i]);
      scanf("%d", &t[t[i]]); // Use character as index into array
    }
    if (scanf("%d", &n) == 1) {
      while (--n >= 0) { // Use pre-decrement
        scanf(" %c", &i);
        putchar(i - '0' + t[i]); // Adjust calculation for character as index
      }
    }
    putchar('\n');
  }
  return 0;
}