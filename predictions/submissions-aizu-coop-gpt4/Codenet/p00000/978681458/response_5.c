#include <stdio.h>

int main(void) {
  register int i, j;
  char buffer[500] = {0};
  char* ptr = buffer;

  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      ptr += sprintf(ptr, "%dx%d=%d\n", i, j, i * j);
    }
  }

  printf("%s", buffer);

  return 0;
}