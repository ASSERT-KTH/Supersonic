#include <stdio.h>

int main(void) {
  int n, s, number, flag;

  while (scanf("%d", &n) == 1 && n != 0) {
    s = n;
    flag = 0;

    for (int i = 0; i < n; i++) {
      scanf("%d", &number);

      if (number == 0) {
        s--;
      } else if (number >= 2) {
        flag = 1;
      }
    }

    if (flag == 1) {
      printf("%d\n", s + 1);
    } else {
      printf("NA\n");
    }
  }

  return 0;
}