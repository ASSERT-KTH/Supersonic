#include <stdio.h>
#include <stdint.h>

int main(void) {
  uint8_t a, b, c; // Use smaller data types to save memory
  scanf("%hhu %hhu %hhu", &a, &b, &c); // Use %hhu format specifier for unsigned char

  // Input validation
  if (a <= 100 && b <= 100 && c <= 100) {
    if (a < b && b < c) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  } else {
    printf("Invalid input\n");
  }

  return 0;
}