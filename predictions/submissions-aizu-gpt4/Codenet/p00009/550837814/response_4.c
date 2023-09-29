#include <math.h>
#include <stdio.h>

#define MAX_NUM 1000000

int main() {
  int i, j, n;
  static int num[MAX_NUM];
  int limit = sqrt(MAX_NUM);

  for (i = 2; i <= limit; i++) {
    if (num[i] == 0) {
      for (j = i * i; j < MAX_NUM; j += i)
        num[j] = 1;
    }
  }

  for (i = 2; i < MAX_NUM; i++) {
    num[i] += num[i - 1];
  }

  while(scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }

  return 0;
}