#include <stdio.h>

#define MAX_LINE_LENGTH 100

int main(void) {
  int s, n, k, flg;
  char line[MAX_LINE_LENGTH];

  while (1) {
    flg = 0;

    fgets(line, MAX_LINE_LENGTH, stdin);
    sscanf(line, "%d", &n);

    if (n == 0)
      break;

    s = n;
    for (int i = 0; i < n; i++) {
      sscanf(line, "%d", &k);

      if (k == 0) {
        s--;
      }
      if (k >= 2) {
        flg = 1;
      }
    }

    if (flg == 1) {
      printf("%d\n", s + 1);
    } else {
      printf("NA\n");
    }
  }

  return 0;
}