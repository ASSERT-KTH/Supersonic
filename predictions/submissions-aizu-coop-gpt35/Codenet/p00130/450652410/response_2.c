#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
  char* train = (char*)malloc(52 * sizeof(char));
  int t = 25, s = 25;

  for (int i = 0; i < 52; ++i)
    train[i] = '\0';

  char buffer[256];
  fgets(buffer, sizeof(buffer), stdin);

  int pos = 0;
  char a = buffer[pos++];
  while (a != EOF && a != '\n') {
    char b = buffer[pos++];
    char c = buffer[pos++];

    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
      
    a = buffer[pos++];
  }

  printf("%s\n", &train[s]);
  free(train);

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