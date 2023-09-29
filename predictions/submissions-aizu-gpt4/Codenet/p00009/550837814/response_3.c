#include <math.h>
#include <stdio.h>

constexpr int MAX_SIZE = 1000000;

int main() {
  int i, j;
  int n;
  char num[MAX_SIZE] = {0};
  num[2] = num[3] = 1;
  for (i = 4; i < MAX_SIZE; i += 2) {
    num[i] = 0;
  }
  int limit = sqrt(MAX_SIZE);
  for (i = 3; i <= limit; i += 2) {
    if (num[i]) {
      for (j = i * i; j < MAX_SIZE; j += (2 * i))
        num[j] = 0;
    }
  }
  for (i = 5; i < MAX_SIZE; i += 2) {
    num[i] += num[i-2];
  }
  for (; scanf("%d", &n) != EOF;) {
    printf("%d\n", num[n]);
  }
  return 0;
}