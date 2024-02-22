#include <cstdio>
#include <cstring>

const int MAXN = 100009;
const long long INF = 1ll << 60;

int num[MAXN];
long long* dp1;
long long* dp2;

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
      
    // Optimize memory usage
    dp1 = new long long[n + 1];
    dp2 = new long long[n + 1];
    
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
      
    std::sort(num, num + n);
    
    for (int i = 1; i <= n; i++)
      dp2[i] = -INF;
      
    dp2[0] = 0;
    
    memset(dp1, 0, sizeof(long long) * (n + 1));
    
    scanf("%d", &m);
    
    bool flag = false;
    
    for (int i = 0; i < m; i++) {
      char s[25];
      scanf("%s %d %s %d", s, &x, s, &y);
      if (x == 0 && y > 0)
        flag = true;
        
      if (s[0] == 'S') {
        for (int j = x; j <= n; j++)
          dp1[j] = dp1[j - x] + y;
      } else {
        for (int j = x; j <= n; j++)
          dp2[j] = dp2[j - x] + y;
      }
    }
    
    if (flag) {
      puts("0");
      continue;
    }
    
    long long ans = INF;
    long long sum;
    
    for (int i = 0; i <= n; i++) {
      if (dp2[i] < 0)
        continue;
        
      sum = i;
      
      // Optimize search operation
      for (int j = 0; j < n; j++) {
        int idx = 0;
        while (idx < n && num[idx] < dp2[i])
          idx++;
        sum += idx;
      }
      
      ans = std::min(ans, sum);
    }
    
    printf("%lld\n", ans);
    
    // Free dynamically allocated memory
    delete[] dp1;
    delete[] dp2;
  }
  
  return 0;
}