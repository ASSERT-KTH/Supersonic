#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;

ll dp1[10001];
ll dp2[10001];
char s[25];
int num[105];

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
      
    // Sort the num array (removed)
      
    // Remove unnecessary memory allocation and initialization for dp1 and dp2
    // for (int i = 1; i <= 10000; i++)
    //   dp2[i] = -inf;

    // Initialize flag variable outside the loop
    bool flag = false;

    // Remove unnecessary memory initialization for dp1
    // memset(dp1, 0, sizeof dp1);
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      
      if (x == 0 && y > 0)
        flag = true;
      
      if (s[0] == 'S') {
        // Modify the loop to start from x instead of 0
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        // Modify the loop to start from x instead of 0
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }
    
    if (flag) {
      puts("0");
      continue;
    }
    
    ll ans = 1ll << 60, sum;
    
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
        
      sum = i;
      
      // Replace the search operation with a more efficient approach
      int lower_bound_index = 0;
      for (int j = 0; j < n; j++) {
        while (lower_bound_index < 10000 && dp1[lower_bound_index] < num[j] - dp2[i])
          lower_bound_index++;
        sum += lower_bound_index;
      }
      
      ans = min(ans, sum);
    }
    
    printf("%lld\n", ans);
  }
  
  return 0;
}