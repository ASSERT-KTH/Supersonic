#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char train[52], a, b, c;
  int t = 25, s = 25;

  a = getchar();
  train[t] = a;

  while ((a = getchar()) != '\n' && a != EOF) {
    b = getchar();
    c = getchar();
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
  }

  train[t+1] = '\0';
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