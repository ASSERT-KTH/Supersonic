#include <stdio.h>

int main() {
  char str[8];
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      sprintf(str, "%dx%d=%d", i, j, i * j);
      puts(str);
    }
  }
  return 0;
}