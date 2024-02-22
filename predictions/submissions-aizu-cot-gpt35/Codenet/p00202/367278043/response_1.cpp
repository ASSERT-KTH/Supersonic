#include <stdio.h>

int n, x, a[30];
bool dp[1001], prime[1001];

int main() {
  prime[0] = true;
  prime[2] = true;
  
  for (int i = 3; i <= 1000; i += 2) {
    prime[i] = true;
  }
  
  for (int i = 3; i <= 1000; i++) {
    if (!prime[i])
      continue;
    
    for (int j = i; i * j <= 1000; j += 2)
      prime[i * j] = false;
  }
  
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    
    dp[0] = true;
    for (int i = 1; i <= x; i++)
      dp[i] = false;
    
    for (int i = 0; i < n; i++) {
      if (a[i] <= x)
        dp[a[i]] = true;
      
      for (int j = i + 1; j < n; j++) {
        if (a[i] + a[j] <= x)
          dp[a[i] + a[j]] = true;
        else
          break;
      }
    }
    
    int result = -1;
    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        result = i;
        break;
      }
    }
    
    if (result != -1)
      printf("%d\n", result);
    else
      printf("NA\n");
  }
}