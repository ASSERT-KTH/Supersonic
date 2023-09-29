#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
const char NUL = '\0';
bool ope_line() {
  char train[52] = {NUL}; // Initialize the array with NUL
  int t = 25, s = 25;
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
  printf("%s\n", &train[s]);
  return a != EOF; // Simplify the return statement
}
int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n && ope_line(); ++i); // Simplify the loop condition
  return 0;
}