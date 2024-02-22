#include <cstdio>
#include <vector>
using namespace std;

int dfs(int s, vector<vector<int>>& b, vector<vector<int>>& f, vector<bool>& v, int now, int maxi, int num) {
  v[now] = true;
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        num++;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      while(b[i][now] != s){
        now = b[i][now];
        v[now] = true;
        if (maxi == f[i][now])
            num++;
        else if (maxi < f[i][now]) {
            maxi = f[i][now];
            num = 1;
        }
      }
      return num;
    }
  }
  if (maxi == f[1][s])
    return num + 1;
  else if (maxi < f[1][s])
    return 1;
  else
    return num;
}

int main() {
  int n;
  while (scanf("%d", &n), n) {
    vector<vector<int>> b(2, vector<int>(n));
    vector<vector<int>> f(2, vector<int>(n));
    vector<bool> v(n, false);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &b[0][i], &f[0][i], &b[1][i], &f[1][i]);
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        int temp = dfs(i, b, f, v, b[0][i], f[0][i], 1);
        ans = ans >= 10007 ? (ans * temp) % 10007 : ans * temp;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}