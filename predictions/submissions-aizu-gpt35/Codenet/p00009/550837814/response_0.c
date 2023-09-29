#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int i, j;
  int n;
  char* num = (char*)malloc(1000000 * sizeof(char));
  for (i = 0; i < 1000000; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;
  for (i = 2; i < sqrt(1000000); i++) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = 0;
    }
  }
  for (i = 1; i < 1000000 - 1; i++) {
    num[i + 1] += num[i];
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  free(num);
  return 0;
}