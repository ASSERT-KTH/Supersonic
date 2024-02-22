#include <stdio.h>
#include <string.h>

void process_input(size_t *n, char *t) {
  memset(t, 0, 999 * sizeof(char));
  char temp;
  
  for (size_t i = 0; i < *n; i++) {
    scanf(" %c", &temp);
    t[i] = temp == '\0' ? 0 : temp;
  }

  scanf("%zu", n);
}

void process_output(size_t n, char *t) {
  char temp;

  for (size_t i = 0; i < n; i++) {
    scanf(" %c", &temp);
    putchar(!t[temp] * temp + t[temp]);
  }
}

int main() {
  size_t n;
  char t[999];

  while (scanf("%zu", &n) != EOF) {
    process_input(&n, t);
    process_output(n, t);
  }

  return 0;
}