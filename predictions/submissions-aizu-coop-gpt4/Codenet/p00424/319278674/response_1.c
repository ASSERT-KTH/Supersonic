#include <stdio.h>
#include <string.h>

int n, t[999];

int main() {
  int i;
  while (scanf("%d", &n) == 1 && n != 0) {
    memset(t, 0, sizeof(t));
    while (n--) {
      i = getchar();
      t[0] = getchar();
    }
    scanf("%d", &n);
    while (n--) {
      i = getchar();
      int ti = t[i];
      putchar(!ti * i + ti);
    }
    putchar('\n');
  }
  return 0;
}