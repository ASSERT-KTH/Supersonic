#include <stdio.h>
#include <string.h>

int main() {
  char table[1000] = {0}; // initialize a large enough array
  char buffer[20]; 

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      int product = i * j; // move multiplication out of printf
      sprintf(buffer, "%dx%d=%d\n", i, j, product); // use sprintf for formatting
      strcat(table, buffer); // concatenate the formatted string to the table
    }
  }
  
  printf("%s", table); // print the entire table at once
  return 0;
}