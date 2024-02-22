#include <stdio.h>
int main(void) {
  int i, j;
  char line[50];
  for (i = 1; i < 10; i++) {
    int pos = 0;
    for (j = i; j < 10; j++) {
      pos += sprintf(line + pos, "%dx%d=%d, ", i, j, i * j);
    }
    line[pos - 2] = '\n';  // replace the last comma with a newline
    printf("%s", line);
  }
  return 0;
}