#include <math.h>
#include <stdio.h>
int main() {
  int i, j;
  int n;
  int num[1000000];
  for (i = 0; i < 10000; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;
  for (i = 2; i < sqrt(1000000); i++) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = 0;
    }
  }
  for (i = 1; i < 1000000 - 1; i++) {
    num[i + 1] += num[i];
  }
  for (; scanf("%d", &n) != EOF;) {
    printf("%d\n", num[n]);
  }
  return 0;
}
