#include <stdio.h>

int main() {
  char buffer[900] = {0}; 
  char *p = buffer;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      int result = i * j;
      p += sprintf(p, "%dx%d=%d\n", i, j, result);
    }
  }

  printf("%s", buffer);
  return 0;
}