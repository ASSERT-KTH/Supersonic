#include <iostream>
#include <algorithm>
#include <climits>

#define ll long long

const int MAXN = 10001;
const ll INF = LLONG_MAX;

int main() {
  int num[MAXN];
  
  int n;
  while (std::cin >> n && n != 0) {
    for (int i = 0; i < n; i++) {
      std::cin >> num[i];
    }
    std::partial_sort(num, num + n, num + MAXN);
    
    ll dp1[MAXN] = {};
    ll dp2[MAXN] = {-INF};
    dp2[0] = 0;
    
    int m;
    bool flag = false;
    for (int i = 0; i < m; i++) {
      char s[25];
      int x, y;
      std::cin >> s >> x >> s >> y;
      if (x == 0 && y > 0) {
        flag = true;
      }
      if (s[0] == 'S') {
        for (int j = x; j < MAXN; j++) {
          dp1[j] = std::max(dp1[j], dp1[j - x] + y);
        }
      } else {
        for (int j = x; j < MAXN; j++) {
          dp2[j] = std::max(dp2[j], dp2[j - x] + y);
        }
      }
    }
    
    if (flag) {
      std::cout << "0\n";
      continue;
    }
    
    ll ans = INF, sum;
    for (int i = 0; i < MAXN; i++) {
      if (dp2[i] < 0) {
        continue;
      }
      sum = i;
      for (int j = 0; j < n; j++) {
        sum += std::lower_bound(dp1, dp1 + MAXN, num[j] - dp2[i]) - dp1;
      }
      ans = std::min(ans, sum);
    }
    
    std::cout << ans << "\n";
  }
  
  return 0;
}