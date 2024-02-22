#include <stdio.h>
const char NUL = '\0';

bool ope_line() {
  char train[52];
  char *t = &train[25];
  char *s = &train[25];

  memset(train, NUL, sizeof(train));

  int a = getchar();
  *t = a;

  while (a != '\n' && a != EOF) {
    int b = getchar();
    a = getchar();

    if (a == '<' && b == '-') {
      *--t = a;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      *++t = a;
  }

  puts(s);

  return a != EOF;
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