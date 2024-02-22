#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char buffer[54];
  int t = 25, s = 25;

  fgets(buffer, sizeof(buffer), stdin);

  for (int i = 0; i < 52; ++i) {
    if (buffer[i] == '<') {
      --t;
      if (t < s)
        s = t;
    } else if (buffer[i] == '>') {
      ++t;
    }
  }

  fputs(&buffer[s], stdout);

  return buffer[0] != '\n';
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