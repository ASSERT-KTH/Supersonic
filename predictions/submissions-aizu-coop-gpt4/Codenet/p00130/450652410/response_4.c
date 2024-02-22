#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ope_line(char *line, char *output) {
  char train[52];
  int t = 25, s = 25;
  memset(train, '\0', sizeof(train));
  char *p = line;
  char c = *p++;
  train[t] = c;
  char a = *p++;
  while (a != '\n' && a != EOF) {
    char b = *p++;
    c = *p++;
    if (a == '<' && b == '-') {
      train[--t] = c;
      if (t < s)
        s = t;
    } else if (a == '-' && b == '>')
      train[++t] = c;
    a = *p++;
  }
  strcat(output, &train[s]);
  strcat(output, "\n");
  return a != EOF;
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  char line[1024];  // Assume each line has at most 1024 characters.
  char output[1024 * 52];  // Assume the total output has at most 1024 * 52 characters.
  output[0] = '\0';  // Initialize the output string to be empty.
  for (int i = 0; i < n; ++i) {
    fgets(line, sizeof(line), stdin);
    if (!ope_line(line, output))
      break;
  }
  puts(output);
  return 0;
}