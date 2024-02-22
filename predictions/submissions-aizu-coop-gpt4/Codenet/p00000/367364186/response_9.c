#include <stdio.h>
#include <string.h>

int main() {
  char output[1000] = ""; // initialize output string
  char buffer[50]; // buffer to hold each line

  for (int i = 1; i < 10; i++) {
    int result = i; // initialize with first multiplication result
    for (int j = 1; j < 10; j++) {
      sprintf(buffer, "%dx%d=%d\n", i, j, result);
      strcat(output, buffer); // append to output string
      result += i; // calculate next multiplication result
    }
  }
  printf("%s", output); // print the output string
  return 0;
}