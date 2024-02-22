#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const char NUL = '\0';

typedef struct {
  char train[52];
  int head;
  int tail;
} Train;

bool ope_line() {
  Train train;
  train.head = 25;
  train.tail = 25;
  for (int i = 0; i < 52; ++i)
    train.train[i] = NUL;

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    int a = c;
    int b = getchar();
    int d = getchar();
    if (a == '<' && b == '-') {
      train.head = (train.head - 1 + 52) % 52;
      train.train[train.head] = d;
      if (train.head < train.tail)
        train.tail = train.head;
    } else if (a == '-' && b == '>') {
      train.tail = (train.tail + 1) % 52;
      train.train[train.tail] = d;
    }
  }

  char buffer[52];
  int bufferIndex = 0;
  for (int i = train.tail; i != train.head; i = (i + 1) % 52) {
    buffer[bufferIndex++] = train.train[i];
  }
  buffer[bufferIndex++] = train.train[train.head];
  buffer[bufferIndex] = '\0';

  printf("%s\n", buffer);

  if (c == EOF)
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