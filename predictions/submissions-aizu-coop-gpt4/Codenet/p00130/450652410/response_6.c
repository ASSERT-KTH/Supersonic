#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
const char NUL = '\0';
#define MAX_LINE 200
bool ope_line() {
  char train[52];
  char line[MAX_LINE];
  int t = 25;
  for (int i = 0; i < 52; ++i)
    train[i] = NUL;
  if(fgets(line, MAX_LINE, stdin) == NULL)
    return false;
  int i=0;
  train[t] = line[i++];
  while (line[i] != '\n' && line[i] != EOF) {
    if (line[i] == '<' && line[i+1] == '-')
      train[--t] = line[i+3];
    else if (line[i] == '-' && line[i+1] == '>')
      train[++t] = line[i+3];
    i+=4;
  }
  printf("%s\n", &train[t]);
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