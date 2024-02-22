#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 1000

int main() {
  char str[MAX_STR_SIZE] = "";
  char temp[MAX_STR_SIZE] = "";

  for (int i = 1; i < 10; i++) {
    str[0] = '\0';  // Reset the string for each outer loop iteration
    for (int j = 1; j < 10; j++) {
      sprintf(temp, "%dx%d=%d\n", i, j, i * j);
      strcat(str, temp);  // Concatenate the multiplication result to the string
    }
    printf("%s", str);  // Print the string once per outer loop iteration
  }

  return 0;
}