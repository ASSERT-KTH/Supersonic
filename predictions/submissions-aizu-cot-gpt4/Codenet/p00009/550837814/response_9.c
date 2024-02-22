#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

int main() {
  int i, j;
  int n;
  bool num[MAX_SIZE];
  
  memset(num, true, sizeof(num));

  num[0] = num[1] = false;

  int limit = sqrt(MAX_SIZE);
  for (i = 2; i <= limit; i++) {
    if (num[i]) {
      for (j = i * i; j < MAX_SIZE; j += i)
        num[j] = false;
    }
  }
  for (i = 2; i < MAX_SIZE; i++) {
    num[i] += num[i - 1];
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  return 0;
}