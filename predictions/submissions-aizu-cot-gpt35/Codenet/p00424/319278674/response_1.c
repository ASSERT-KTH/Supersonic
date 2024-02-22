#include <stdio.h>
#include <string.h>

int t[999];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(t, 0, sizeof(t));
    for (; n > 0; n--) {
      int i;
      char c;
      scanf(" %d %c", &i, &c);
      t[i] = c;
    }
    scanf("%d", &n);
    for (; n > 0; n--) {
      int i;
      scanf(" %d", &i);
      putchar(t[i]);
    }
    putchar('\n');
  }
  return 0;
}