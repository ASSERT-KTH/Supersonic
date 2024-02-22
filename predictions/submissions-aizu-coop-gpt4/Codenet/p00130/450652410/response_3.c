#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ope_line() {
  char train[52];
  memset(train, '\0', sizeof(train)); // Initialize array using memset.

  int t = 25;
  char line[104];
  fgets(line, sizeof(line), stdin); // Read entire line at once.

  for (int i = 0; line[i] != '\n' && line[i] != EOF; i += 3) {
    char a = line[i];
    char b = line[i + 1];
    char c = line[i + 2];
    if (a == '<' && b == '-') {
      train[--t] = c;
    } else if (a == '-' && b == '>') {
      train[++t] = c;
    }
  }

  char *s = strchr(train, '\0'); // Find starting point of train.
  printf("%s\n", s);

  return line[0] != EOF;
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