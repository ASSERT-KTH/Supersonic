#include <stdio.h>

int main(void) {
  int i, j;
  int result[9][9]; // Store the multiplication results
  char buffer[256]; // Buffer for storing the formatted output

  // Calculate and store the multiplication results
  for (int counter = 1; counter <= 81; counter++) {
    i = (counter - 1) / 9 + 1;
    j = (counter - 1) % 9 + 1;
    result[i-1][j-1] = i * j;
  }

  // Format the output and store it in the buffer
  int buffer_pos = 0;
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++) {
      buffer_pos += sprintf(buffer + buffer_pos, "%dx%d=%d\n", i, j, result[i-1][j-1]);
    }
  }

  // Print the entire buffer in a single call to printf
  printf("%s", buffer);

  return 0;
}