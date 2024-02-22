#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int* num;

int main() {
  int i, j;
  int n;
  double sqrt_limit = sqrt(1000000);

  num = malloc(1000000 * sizeof(int));
  if(!num){
      printf("Memory allocation failed.");
      return 1;
  }

  for (i = 0; i < 1000000; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;

  for (i = 2; i < sqrt_limit; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = 0;
    }
  }
  
  for (i = 1; i < 1000000 - 1; i++) {
    num[i + 1] += num[i];
  }

  while(scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }

  free(num); // free memory after use
  return 0;
}