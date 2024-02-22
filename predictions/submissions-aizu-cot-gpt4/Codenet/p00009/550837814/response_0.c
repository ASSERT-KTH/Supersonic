#include <math.h>
#include <stdio.h>
int main() {
  int i, j;
  long long int n;
  long long int num[1000000];
  for (i = 0; i < 1000000; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;
  int limit = sqrt(1000000);
  for (i = 2; i < limit; i++) {
    if (num[i] == 1) {
      j = i * i;
      while(j < 1000000){
        num[j] = 0;
        j += i;
      }
    }
  }
  for (i = 1; i < 1000000 - 1; i++) {
    num[i + 1] += num[i];
  }
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    printf("%lld\n", num[i]);
  }
  return 0;
}