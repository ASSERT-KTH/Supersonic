#include <string.h>
#include <stdio.h>

n, t[999];
int main(i) {
  while (scanf("%d", &n) == 1 && n != 0) {
    memset(t, 0, 999 * sizeof(int));
    for (; n--; t[i] = t[0])
      scanf(" %c %c", &i, t);
    scanf("%d", &n);
    char buf[1000];
    fgets(buf, sizeof(buf), stdin);
    for (int j = 0; j < n; j++) {
      i = buf[j];
      putchar(t[i] ? t[i] : i);
    }
    puts("");
  }
  return 0;
}