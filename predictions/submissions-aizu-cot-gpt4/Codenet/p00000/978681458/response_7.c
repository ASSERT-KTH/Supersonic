#include <stdio.h>

int main(void) {
  char output[361] = ""; // 361 is the total number of characters in the final output string
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      char temp[10];  // Temporary string to hold the result of one multiplication
      sprintf(temp, "%dx%d=%d\n", i, j, i * j);
      strcat(output, temp);  // Append the result to the output string
    }
  }
  printf("%s", output);  // Print the output string once
  return 0;
}