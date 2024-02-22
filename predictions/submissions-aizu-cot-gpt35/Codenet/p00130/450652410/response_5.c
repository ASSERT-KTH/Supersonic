#include <stdio.h>
#include <string.h>

const char* NUL = NULL;

void ope_line() {
  char* train = malloc(52 * sizeof(char));
  int t = 25, s = 25;
  memset(train, 0, 52 * sizeof(char));

  int n;
  scanf("%d ", &n);

  for (int i = 0; i < n; ++i) {
    char a, b, c;
    scanf("%c%c%c", &a, &b, &c);

    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
  }

  puts(&train[s]);
  free(train);
}

int main(int argc, char **argv) {
  while (1) {
    if (scanf("%d\n", &n) != 1)
      break;
    ope_line();
  }

  return 0;
}