#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char train[52] = "";
  int t = 25, s = 25;
  char c = getchar();
  train[t] = c;
  char a = getchar();
  while (a != '\n' && a != EOF) {
    c = a;
    a = getchar();
    if (c == '<' && a == '-') {
      c = getchar();
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (c == '-' && a == '>')
      train[++t] = getchar();
    else
      a = getchar();
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