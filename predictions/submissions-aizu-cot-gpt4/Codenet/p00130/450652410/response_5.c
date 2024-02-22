#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char train[256];
  int t = 128, s = 128;
  int a, b, c;
  while (scanf("%c%c%c", &a, &b, &c) == 3 && a != '\n') {
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
  }
  printf("%s\n", &train[s]);
  if (a == EOF)
    return false;
  return true;
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