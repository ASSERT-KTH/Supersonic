#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int i, j, n, max = 0;
  int num[max], limit;
  
  while(scanf("%d", &n) != EOF) {
    if(n > max) max = n;
  }
  
  num = (int*)malloc(max * sizeof(int));

  for (i = 0; i < max; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;

  limit = sqrt(max);
  for (i = 2; i <= limit; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < max; j += i)
        num[j] = 0;
    }
  }
  for (i = 1; i < max; i++) {
    num[i + 1] += num[i];
  }

  printf("%d\n", num[n]);
  
  free(num);
  
  return 0;
}