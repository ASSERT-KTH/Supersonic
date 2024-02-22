#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
  int i, j;
  int n;
  bool num[1000000];
  for (i = 0; i < 1000000; i++) {
    num[i] = true;
  }
  num[0] = num[1] = false;
  int limit = (int)sqrt(1000000);
  for (i = 2; i <= limit; i++) {
    if (num[i]) {
      for (j = i * i; j < 1000000; j += i) {
        num[j] = false;
      }
      num[i] += num[i-1];
    }
  }
  for (i = limit+1; i < 1000000; i++) {
    num[i] += num[i-1];
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  return 0;
}