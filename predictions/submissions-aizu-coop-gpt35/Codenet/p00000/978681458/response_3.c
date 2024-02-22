#include <stdio.h>

int main(void) {
  int i, j;
  char line[20]; // Character array to hold the line to be printed
  int pos = 0; // Position tracker for writing to the line array

  for (i = 1; i < 10; i++) {
    pos = 0; // Reset position for each new line

    for (j = 1; j <= i; j++) {
      // Construct the line
      pos += sprintf(line + pos, "%dx%d=%d ", i, j, i * j);
    }

    // Print the line
    printf("%s\n", line);
  }

  return 0;
}