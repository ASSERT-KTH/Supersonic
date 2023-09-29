#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, b[2][100100], f[2][100100];
bool v[100100];
vector<int> adj[100100];
int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  for (int i = 0; i < adj[now].size(); i++) {
    int nxt = adj[now][i];
    if (!v[nxt]) {
      if (maxi == f[i][now])
        num++;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      if (nxt == s)
        return num;
      return dfs(s, nxt, maxi, num);
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
  while (cin >> n, n) {
    memset(v, false, sizeof(v));
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      adj[i].clear();
      v[i] = false;
    }
    for (int i = 0; i < n; i++) {
      adj[b[0][i]].push_back(b[1][i]);
      adj[b[1][i]].push_back(b[0][i]);
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }
    cout << ans << endl;
  }
}