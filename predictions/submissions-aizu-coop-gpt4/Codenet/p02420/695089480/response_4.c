#include <stdio.h>
#include <string.h>

int i, m, h, t, a;
int main() {
  char s[201];
  while (scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s); // calculate the length once
    t = 0; // reset t for each string
    for (i = 0; i < m; i++) {
      scanf("%d", &h);
      t += h;
      printf("%c", s[(t) % a]); // print the shifted character
    }
    for (; i < a; i++) // continue printing the rest of the string
      printf("%c", s[(t + i) % a]);
    puts("");
  }
  return 0;
}