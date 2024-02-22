#include <stdio.h>

int main() {
  int i, j;
  int num[1000000] = {0};

  for (i = 2; i < 1000; i++) {
    if (num[i] == 0) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = 1;
    }
  }

  int count = 0;
  for (i = 2; i < 1000000; i++) {
    if (num[i] == 0)
      count++;
    num[i] = count;
  }

  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }

  return 0;
}