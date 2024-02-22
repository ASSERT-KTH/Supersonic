#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000000

char num[MAX/8 + 1];

#define IsComposite(x)  (num[x>>3]&(1<<(x&7)))
#define MarkComposite(x) (num[x>>3]|=(1<<(x&7)))

int main() {
  int i, j;
  int n;
  int sqrtN = (int)sqrt(MAX);
  
  memset(num, 0, sizeof num);
  
  for (i = 2; i <= sqrtN; i++) {
    if (!IsComposite(i)) {
      for (j = i * i; j < MAX; j += i)
        MarkComposite(j);
    }
  }
  
  for (i = 2; i < MAX; i++) {
    if (!IsComposite(i)) num[i]++;
    num[i] += num[i-1];
  }
  
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  
  return 0;
}