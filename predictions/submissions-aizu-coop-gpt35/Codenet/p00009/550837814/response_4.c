#include <math.h>
#include <stdio.h>

int main() {
  int i, j;
  int n;
  int num[1000000] = {0}; // Automatically initialized to 0

  for (i = 2; i < sqrt(1000000); i++) {
    if (num[i] == 0) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = 1;
    }
  }

  for (i = 1; i < 1000000 - 1; i++) {
    num[i + 1] += num[i];
  }

  for (; scanf("%d\n", &n) != EOF;) {
    printf("%d\n", num[n]);
  }

  return 0;
}