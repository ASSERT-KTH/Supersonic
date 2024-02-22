#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_COMMANDS 1000

bool ope_line() {
  char train[52], commands[MAX_COMMANDS];
  int t = 25, s = 25;
  if (fgets(commands, MAX_COMMANDS, stdin) == NULL) return false;
  int i = 0;
  char a = commands[i++];
  train[t] = a;
  while (true) {
    a = commands[i++];
    if (a == '\n' || a == EOF) break;
    int b = commands[i++];
    char c = commands[i++];
    if ((a ^ b) == ('<' ^ '-')) {
      if (a == '<') {
        train[--t] = c;
        if (t < s) s = t;
      } else train[++t] = c;
    }
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