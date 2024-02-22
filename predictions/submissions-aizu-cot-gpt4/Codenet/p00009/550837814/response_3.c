#include <math.h>
#include <stdio.h>
bool num[1000000];
int main() {
  int i, j;
  int n;
  int limit = sqrt(1000000);
  for (i = 2; i <= limit; i++) {
    if (!num[i]) {
      for (j = 2*i; j < 1000000; j += i)
        num[j] = true;
    }
  }
  for (i = 2; i < 1000000; i++) {
    num[i] += num[i-1];
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  return 0;
}