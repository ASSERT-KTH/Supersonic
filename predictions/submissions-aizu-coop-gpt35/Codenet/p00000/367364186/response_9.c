#include <stdio.h>

int main() {
  char buffer[1000]; // Buffer to store the multiplication table

  char* ptr = buffer; // Pointer to the current position in the buffer

  for (int k = 1; k <= 9; k++) {
    for (int l = 1; l <= 9; l++) {
      // Calculate the multiplication result
      int result = k * l;

      // Convert the numbers to strings
      char num1[4], num2[4], res[6];
      sprintf(num1, "%d", k);
      sprintf(num2, "%d", l);
      sprintf(res, "%d", result);

      // Copy the numbers and result to the buffer
      for (int i = 0; num1[i] != '\0'; i++) {
        *ptr++ = num1[i];
      }
      *ptr++ = 'x';
      for (int i = 0; num2[i] != '\0'; i++) {
        *ptr++ = num2[i];
      }
      *ptr++ = '=';
      for (int i = 0; res[i] != '\0'; i++) {
        *ptr++ = res[i];
      }
      *ptr++ = '\n';
    }
  }

  // Print the entire buffer
  printf("%s", buffer);

  return 0;
}