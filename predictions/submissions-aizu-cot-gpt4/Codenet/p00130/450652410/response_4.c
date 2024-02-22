#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char train[52];
  char *start = &train[25];
  char *t = start;
  char line[5];
  while (fgets(line, sizeof(line), stdin) && line[0] != '\n') {
    if (line[0] == '<' && line[1] == '-') {
      *(--t) = line[2];
      if (t < start)
        start = t;
    } else if (line[0] == '-' && line[1] == '>')
      *(++t) = line[2];
  }
  *++t = '\0'; // ensure null-termination
  printf("%s\n", start);
  return line[0] != '\n';
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}