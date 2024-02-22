#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void ope_line() {
  char train[52];
  int t = 25, s = 25;
  fgets(train, sizeof(train), stdin);

  for (int i = 0; train[i] != '\n' && train[i] != '\0'; i++) {
    if (train[i] == '<' && train[i+1] == '-') {
      train[--t] = train[i+2];
      if (t < s)
        s = t;
      i += 2;
    } else if (train[i] == '-' && train[i+1] == '>') {
      train[++t] = train[i+2];
      i += 2;
    }
  }

  for (int i = s; train[i] != '\n' && train[i] != '\0'; i++) {
    putchar(train[i]);
  }
  putchar('\n');
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    ope_line();
  }
  return 0;
}