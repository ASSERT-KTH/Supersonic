#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
const char NUL = '\0';
bool ope_line() {
  char train[52];
  int t = 25, s = 25;
  for (int i = 0; i < 52; ++i)
    train[i] = NUL;
  int c, a = getchar();
  train[t] = c = a;
  while ((a = getchar()) != '\n' && a != EOF) {
    int b = getchar();
    c = getchar();
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
  }
  printf("%s\n", &train[s]);
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
