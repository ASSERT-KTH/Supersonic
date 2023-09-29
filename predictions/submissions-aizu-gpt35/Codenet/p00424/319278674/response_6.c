#include <stdio.h>
#include <string.h>

#define MAX_N 999

int t[MAX_N];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(t, 0, sizeof(t));
    while (n--) {
      int i;
      char c1, c2;
      scanf(" %c %c", &c1, &c2);
      i = c1 - 'a';
      t[i] = c2;
    }
    scanf("%d", &n);
    while (n--) {
      int i;
      char c;
      scanf(" %c", &c);
      i = c - 'a';
      putchar(t[i]);
    }
    putchar('\n');
  }
  return 0;
}