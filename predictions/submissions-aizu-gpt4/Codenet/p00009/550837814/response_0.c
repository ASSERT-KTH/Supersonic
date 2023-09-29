#include <stdio.h>
#define MAX 1000000

bool num[MAX];
int primeSum[MAX];

int main() {
  int i, j;
  int n;
  
  for (i = 2; i < MAX; i++) {
    num[i] = true;
  }
  
  for (i = 2; i * i < MAX; i++) {
    if (num[i]) {
      for (j = i * i; j < MAX; j += i)
        num[j] = false;
    }
  }

  for (i = 2; i < MAX; i++) {
    primeSum[i] = primeSum[i - 1] + num[i];
  }

  while(scanf("%d", &n) != EOF) {
    printf("%d\n", primeSum[n]);
  }
  
  return 0;
}