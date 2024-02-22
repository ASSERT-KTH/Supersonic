#include <math.h>
#include <stdio.h>
int main() {
  int i, j;
  int n;
  int num[1000000];
  for (i = 0; i < 1000000; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;
  for (i = 2; i * i < 1000000; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = 0;
    }
  }
  int cumulativeSum[1000000];
  cumulativeSum[0] = num[0];
  for (i = 1; i < 1000000; i++) {
    cumulativeSum[i] = cumulativeSum[i - 1] + num[i];
  }
  for (; scanf("%d", &n) != EOF;) {
    printf("%d\n", cumulativeSum[n]);
  }
  return 0;
}