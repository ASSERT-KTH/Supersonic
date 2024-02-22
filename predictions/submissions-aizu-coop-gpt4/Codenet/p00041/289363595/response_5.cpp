#include <stdio.h>
#include <string.h>

int main() {
  int a[4];
  char output[110001]; // Create a buffer to hold 110000 '(' characters and one '\0' character
  memset(output, '(', 110000); // Fill the array with '(' characters
  output[110000] = '\0'; // Null-terminate the string

  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }
    printf("%s", output); // Print the string
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
}