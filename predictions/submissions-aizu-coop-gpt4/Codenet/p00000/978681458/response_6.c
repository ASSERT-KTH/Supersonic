#include <stdio.h>

int main(void) {
  int i, j, result;
  char buffer[8192] = {0}; // Buffer to store the strings
  char *ptr = buffer; // Pointer to the current position in the buffer

  for (i = 1; i < 10; i++) {
    result = i;
    for (j = 1; j < 10; j++) {
      ptr += sprintf(ptr, "%dx%d=%d\n", i, j, result);
      result += i;
    }
  }

  printf("%s", buffer); // Print all strings at once

  return 0;
}