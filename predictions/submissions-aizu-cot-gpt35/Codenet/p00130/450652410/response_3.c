#include <stdio.h>

const char NUL = '\0';

bool ope_line() {
  char train[52];
  int pos = 25;

  char c = getchar();
  train[pos] = c;
  char a = getchar();

  while (a != '\n') {
    char c = getchar();

    if (a == '<') {
      --pos;
    } else if (a == '-') {
      ++pos;
    }

    train[pos] = c;
    a = getchar();
  }

  puts(&train[pos]);

  return (a != EOF);
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);

  for (int i = 0; i < n; ++i) {
    if (!ope_line()) {
      break;
    }
  }

  return 0;
}