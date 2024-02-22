#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j;
  char str[30];
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      sprintf(str, "%dx%d=%d", i, j, i * j);
      puts(str);
    }
  }
  return 0;
}