#include <stdio.h>

int main() {
  char buffer[256];
  char* format = "%dx%d=%d\n";
  int bufferIndex = 0;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j <= i; j++) {
      bufferIndex += sprintf(buffer + bufferIndex, format, i, j, i * j);
    }
  }

  printf("%s", buffer);
  
  return 0;
}