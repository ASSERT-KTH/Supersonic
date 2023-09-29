#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000

int main() {
  int i, j, n;
  int *num = (int *)calloc(MAX_NUM, sizeof(int));
  if (num == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  for (i = 0; i < MAX_NUM; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;
  int sqrt_max_num = (int)sqrt(MAX_NUM);
  for (i = 2; i < sqrt_max_num; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < MAX_NUM; j += i)
        num[j] = 0;
    }
  }
  for (i = 1; i < MAX_NUM - 1; i++) {
    num[i + 1] += num[i];
  }
  while (scanf("%d", &n) != EOF) {
    if (n < 0 || n >= MAX_NUM) {
      printf("Input out of range!\n");
      continue;
    }
    printf("%d\n", num[n]);
  }
  free(num);
  return 0;
}