#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

bool process_line(char* train, int* s, int* t) {
  char buffer[BUFFER_SIZE];
  size_t n = fread(buffer, 1, BUFFER_SIZE, stdin);
  for (size_t i = 0; i < n; ++i) {
    char a = buffer[i++];
    char b = buffer[i++];
    char c = buffer[i];
    if (a == '<' && b == '-') {
      train[--(*t)] = c;
      if (*t < *s)
        *s = *t;
    } else if (a == '-' && b == '>')
      train[++(*t)] = c;
  }
  printf("%s\n", &train[*s]);
  return n == BUFFER_SIZE;
}

int main(int argc, char **argv) {
  int n;
  scanf("%d\n", &n);
  char* train = malloc(52 * n * sizeof(char));
  int s = 25 * n, t = s;
  for (int i = 0; i < n; ++i) {
    if (!process_line(train, &s, &t))
      break;
  }
  free(train);
  return 0;
}