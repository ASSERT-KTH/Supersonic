#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ope_line() {
  char train[52];
  int t = 25, s = 25;
  memset(train, '\0', sizeof(train));

  int c = getchar();
  train[t] = c;
  int a = getchar();

  while (a != '\n' && a != EOF) {
    int b = getchar();
    c = getchar();

    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>') {
      train[++t] = c;
    }

    a = getchar();
  }

  for (int i = s; i <= t; i++) {
    putchar(train[i]);
  }
  putchar('\n');

  if (a == EOF)
    return 0;

  return 1;
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