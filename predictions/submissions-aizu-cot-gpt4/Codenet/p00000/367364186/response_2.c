#include <stdio.h>

int main() {
  char buffer[900] = {0}; // 900 is the maximum size needed (9*9*10)
  char* ptr = buffer;
  
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      ptr += sprintf(ptr, "%dx%d=%d\n", i, j, i * j); // sprintf returns the number of characters written
    }
  }
  
  puts(buffer); // print the buffer at once
  
  return 0;
}