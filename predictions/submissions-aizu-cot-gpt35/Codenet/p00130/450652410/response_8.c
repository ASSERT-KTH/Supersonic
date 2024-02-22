#include <stdio.h>
const int TRAIN_SIZE = 52;

bool ope_line() {
  char* train = malloc(TRAIN_SIZE + 1);
  int t = TRAIN_SIZE / 2, s = TRAIN_SIZE / 2;
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
  train[TRAIN_SIZE] = '\0';
  puts(&train[s]);
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