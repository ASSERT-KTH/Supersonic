#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 1000000

int main() {
  int i, j, n;
  bool num[MAX_NUM] = { true };
  
  for (i = 2; i < sqrt(MAX_NUM); i++) {
    if (num[i]) {
      for (j = i * i; j < MAX_NUM; j += i)
        num[j] = false;
    }
  }
  
  int count[MAX_NUM + 1] = {};
  for (i = 2; i <= MAX_NUM; i++) {
    count[i] = count[i - 1] + num[i];
  }
  
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", count[n]);
  }
  
  return 0;
}