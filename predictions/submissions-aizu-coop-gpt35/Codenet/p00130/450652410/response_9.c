#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ope_line() {
  char* train = NULL;
  int t = 25, s = 25;

  char input[100];
  fgets(input, sizeof(input), stdin);

  int len = strlen(input);
  train = malloc((len + 1) * sizeof(char));
  strncpy(train, input, len);
  train[len] = '\0';

  int i = 0;
  while (train[i] != '\n' && train[i] != '\0') {
    if (train[i] == '<' && train[i + 1] == '-') {
      train[--t] = train[i + 2];
      if (t < s)
        s = t;
    } else if (train[i] == '-' && train[i + 1] == '>') {
      train[++t] = train[i + 2];
    }
    i += 3;
  }

  printf("%s\n", &train[s]);

  free(train);

  if (train[i] == '\0')
    return false;
  return true;
}

int main(int argc, char** argv) {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    if (!ope_line())
      break;
  }
  return 0;
}