#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;

int n, b[2][100100], f[2][100100];

int dfs(int s, int now, int maxi, int num) {
  unordered_set<int> visited;
  stack<int> st;
  st.push(now);
  visited.insert(now);

  while (!st.empty()) {
    now = st.top();
    st.pop();
    for (int i = 0; i < 2; i++) {
      if (visited.count(b[i][now]) == 0) {
        if (maxi == f[i][now])
          num++;
        else if (maxi < f[i][now]) {
          maxi = f[i][now];
          num = 1;
        }
        if (b[i][now] == s)
          return num;
        st.push(b[i][now]);
        visited.insert(b[i][now]);
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
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
    }
    int ans = 1;
    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
      if (visited.count(i) == 0) {
        visited.insert(i);
        int dfs_result = dfs(i, b[0][i], f[0][i], 1);
        ans = (ans * dfs_result) % 10007;
      }
    }
    cout << ans << endl;
  }
}