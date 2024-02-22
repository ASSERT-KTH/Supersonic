#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> b(2, vector<int>(100100)), f(2, vector<int>(100100));
vector<bool> v(100100);

int dfs(int s) {
  int maxi = -1, num = 0;
  vector<int> stack;
  stack.push_back(s);
  while (!stack.empty()) {
    int now = stack.back();
    stack.pop_back();
    v[now] = true;
    for (int i = 0; i < 2; i++) {
      if (!v[b[i][now]]) {
        if (maxi == f[i][now])
          num++;
        else if (maxi < f[i][now]) {
          maxi = f[i][now];
          num = 1;
        }
        if (b[i][now] != s)
          stack.push_back(b[i][now]);
        else
          return num;
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
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        ans = (ans * dfs(i)) % 10007;
      }
    }
    cout << ans << endl;
  }
  return 0;
}