#include <stdio.h>

int main() {
  char s[201];
  int i, m, h, t, a;

  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);

    // Calculate the sum of m integers
    t = m * (m - 1) / 2;

    // Calculate the circular index outside the loop
    int index = t % a;

    for (i = 0; i < a; i++) {
      putchar(s[index]);
      index = (index + 1) % a;
    }

    printf("\n");
  }

  return 0;
}