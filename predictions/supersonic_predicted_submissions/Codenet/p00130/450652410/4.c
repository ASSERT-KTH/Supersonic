#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
const char NUL = '\0';
bool ope_line() {
  char train[52];
  int t = 25, s = 25;
  for (int i = 0; i < 52; ++i)
    train[i] = NUL;
  int c = getchar();
  train[t] = c;
  int a = getchar();
  while (a != '\n' && a != EOF) {
    int b = getchar();
    c = getchar();
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
    a = getchar();
  }
  cout << train[s] << endl;
  if (a == EOF)
    return false;
  return true;
}
int main(int argc, char **argv) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}
