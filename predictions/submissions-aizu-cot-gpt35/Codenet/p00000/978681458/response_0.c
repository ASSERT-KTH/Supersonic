#include <stdio.h>

int main(void) {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      char buffer[16];
      sprintf(buffer, "%dx%d=%d\n", i, j, i * j);
      printf("%s", buffer);
    }
  }
  return 0;
}