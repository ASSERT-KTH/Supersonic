#include <stdio.h>

int main() {
  int i, j;
  int n;
  int num[999999];

  num[0] = num[1] = 0;
  for (i = 2; i * i < 1000000; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000000; j += 2 * i)
        num[j] = 0;
    }
  }
  for (i = 1; i < 999999; i++) {
    num[i + 1] += num[i];
  }
  for (; scanf("%d", &n) != EOF;) {
    printf("%d\n", num[n]);
  }
  return 0;
}