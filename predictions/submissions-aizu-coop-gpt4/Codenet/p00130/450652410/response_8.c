#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const char NUL = '\0';

bool ope_line() {
  char train[52], line[104];
  int t = 25, s = 25;

  for (int i = 0; i < 52; ++i)
    train[i] = NUL;

  fgets(line, 104, stdin);
  
  int i = 0;
  train[t] = line[i++];

  while (line[i] != '\n' && line[i] != EOF) {
    if (line[i] == '<' && line[i+1] == '-') {
      train[--t] = line[i+2]; 
      if (t < s)
        s = t;
    } else if (line[i] == '-' && line[i+1] == '>') {
      train[++t] = line[i+2];
    }
    i += 3;
  }

  printf("%s\n", &train[s]);
  if (line[i] == EOF)
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