#include <stdio.h>

int main() {
  char table[1000];  // An array to hold the multiplication table as a string
  char* ptr = table; // Pointer to the current position in the table array

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      // Calculate the multiplication and write it to the table array
      ptr += sprintf(ptr, "%dx%d=%d\n", i, j, i * j);
    }
  }

  // Print the multiplication table using fputs
  fputs(table, stdout);

  return 0;
}