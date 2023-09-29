#include <math.h>
#include <stdio.h>
#define MAX 1000000

int main() {
  int i, j;
  int n;
  int num[MAX] = {0};
  num[2] = 1;
  for (i = 3; i < MAX; i+=2) {
    num[i] = 1;
  }
  int limit = sqrt(MAX);
  for (i = 3; i <= limit; i+=2) {
    if (num[i]) {
      for (j = i * i; j < MAX; j += (2*i)) {
        num[j] = 0;
      }
    }
  }
  for (i = 3; i < MAX; i+=2) {
    num[i] += num[i-2];
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", n%2 == 0 ? num[n-1] : num[n]);
  }
  return 0;
}