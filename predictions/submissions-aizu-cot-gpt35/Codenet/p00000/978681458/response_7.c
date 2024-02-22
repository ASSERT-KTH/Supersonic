#include <stdio.h>

int main(void) {
  int i, j;
  char buffer[100]; // buffer to store the output strings
  int bufferIndex = 0; // index to keep track of the buffer position

  for (i = 1; i < 10; i++) {
    for (j = i; j < 10; j++) {
      bufferIndex += sprintf(buffer + bufferIndex, "%dx%d=%d\n", i, j, i * j);
    }
  }

  printf("%s", buffer); // print the buffer

  return 0;
}