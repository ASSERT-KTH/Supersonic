#include <math.h>
#include <stdio.h>

#define MAX 1000000

int main() {
  int i, j, n;
  int num[MAX] = {0};
  num[0] = num[1] = 1;
  for (i = 2; i < sqrt(MAX); i++) {
    if (num[i] == 0) {
      for (j = i * i; j < MAX; j += i)
        num[j] = 1;
    }
  }
  for (i = 1; i < MAX; i++) {
    num[i] += num[i - 1];
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  return 0;
}