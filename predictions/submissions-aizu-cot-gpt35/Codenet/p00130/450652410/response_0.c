#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char NUL = '\0';

bool ope_line(char* train) {
  int t = 25, s = 25;
  int a;
  fgets(train, 52, stdin);
  train[strcspn(train, "\n")] = NUL;
  a = train[0];
  for (int i = 1; train[i] != NUL; i += 2) {
    int b = train[i];
    int c = train[i + 1];
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
    a = b;
  }
  printf("%s\n", &train[s]);
  if (a == EOF)
    return false;
  return true;
}

int main(int argc, char** argv) {
  int n;
  scanf("%d\n", &n);
  char train[52];
  for (int i = 0; i < n; ++i) {
    if (!ope_line(train))
      break;
  }
  return 0;
}