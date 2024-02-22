#include <stdio.h>

int main(void) {
  char* table[81];
  int index = 0;
  
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      char buffer[20];
      sprintf(buffer, "%dx%d=%d", i, j, i*j);
      table[index] = buffer;
      index++;
    }
  }
  
  for (int i = 0; i < 81; i++) {
    puts(table[i]);
  }
  
  return 0;
}