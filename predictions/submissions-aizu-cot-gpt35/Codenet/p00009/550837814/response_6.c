#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  int i;
  int num[1000000];

  memset(num, 1, sizeof(num));
  num[0] = num[1] = 0;

  for (i = 2; i < sqrt(1000000); i++) {
    if (num[i] == 1) {
      for (int j = i * i; j < 1000000; j += i)
        num[j] = 0;
    }
  }

  for (i = 2; i < 1000000 - 1; i++) {
    num[i + 1] += num[i];
  }

  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }

  return 0;
}