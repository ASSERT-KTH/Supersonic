#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int BUF_SIZE = 1024;
const char NUL = '\0';

bool ope_line() {
  char train[52];
  int t = 25, s = 25;
  for (int i = 0; i < 52; ++i)
    train[i] = NUL;

  char buffer[BUF_SIZE];
  fgets(buffer, BUF_SIZE, stdin);

  int i = 0;
  while (buffer[i] != '\n' && buffer[i] != EOF) {
    if (buffer[i] == '<' && buffer[i+1] == '-') {
      train[t--] = buffer[i+2];
      if (t < s)
        s = t;
    } else if (buffer[i] == '-' && buffer[i+1] == '>')
      train[t++] = buffer[i+2];
    i+=3;
  }

  printf("%s\n", &train[s]);
  if (buffer[i] == EOF)
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