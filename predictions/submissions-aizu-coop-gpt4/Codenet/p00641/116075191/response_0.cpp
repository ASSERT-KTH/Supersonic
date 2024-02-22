#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N = 100100;
const int MOD = 10007;

int dfs(int s, int now, int maxi, int num, vector<bool>& v, vector<vector<int>>& b, vector<vector<int>>& f) {
  stack<int> stk;
  stk.push(now);
  v[now] = true;

  while (!stk.empty()) {
    now = stk.top();
    stk.pop();

    for (int i = 0; i < 2; i++) {
      if (!v[b[i][now]]) {
        if (maxi == f[i][now])
          num++;
        else if (maxi < f[i][now]) {
          maxi = f[i][now];
          num = 1;
        }
        if (b[i][now] == s)
          return num;

        stk.push(b[i][now]);
        v[b[i][now]] = true;
      }
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
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n, n) {
    vector<vector<int>> b(2, vector<int>(n)), f(2, vector<int>(n));
    vector<bool> v(n, false);

    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        ans = (ans * (dfs(i, b[0][i], f[0][i], 1, v, b, f) % MOD)) % MOD;
      }
    }

    cout << ans << endl;
  }

  return 0;
}