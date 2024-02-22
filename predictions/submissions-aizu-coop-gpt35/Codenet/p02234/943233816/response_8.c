#include <stdio.h>
#include <string.h>

#define INF 100000000
#define MAX_SIZE 101

int m[MAX_SIZE * (MAX_SIZE + 1) / 2];
int p[MAX_SIZE];

int matrixChainOrder(int pl) {
  int n = pl - 1;
  
  // Initialize matrix m with INF
  memset(m, INF, sizeof(m[0]) * (n * (n + 1) / 2));
  
  for (int i = 1; i <= n; i++) {
    m[i * (i - 1) / 2 + i] = 0;
  }
  
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      int temp = INF;
      
      for (int k = i; k < j; k++) {
        int q = m[k * (k - 1) / 2 + i] + m[j * (j - 1) / 2 + k + 1] + p[i - 1] * p[k] * p[j];
        if (temp > q)
          temp = q;
      }
      
      m[j * (j - 1) / 2 + i] = temp;
    }
  }
  
  return m[n * (n - 1) / 2 + 1];
}

int main() {
  int pl;
  scanf("%d", &pl);
  
  for (int i = 0; i < pl; i++) {
    scanf("%d", &p[i]);
    if (i < pl - 1)
      scanf("%*d");
  }
  
  int result = matrixChainOrder(pl);
  printf("%d\n", result);
  
  return 0;
}