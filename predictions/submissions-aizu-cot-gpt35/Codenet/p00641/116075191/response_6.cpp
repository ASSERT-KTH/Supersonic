#include <iostream>
using namespace std;

int n, b[2][100100], f[2][100100];
bool v[100100];

int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      int nextMaxi = max(maxi, f[i][now]);
      int nextNum = (nextMaxi == f[i][now]) ? num + 1 : 1;
      
      if (b[i][now] == s)
        return nextNum;
      
      return dfs(s, b[i][now], nextMaxi, nextNum);
    }
  }
  
  return (maxi == f[1][s]) ? num + 1 : ((maxi < f[1][s]) ? 1 : num);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }
    
    cout << ans << endl;
    
    // Reset visited array for the next iteration
    for (int i = 0; i < n; i++) {
      v[i] = false;
    }
  }
  
  return 0;
}