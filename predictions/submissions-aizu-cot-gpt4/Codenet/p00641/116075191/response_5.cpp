#include <iostream>
#include <stack>
using namespace std;
int n, b[2][100100], f[2][100100];
bool v[100100];

int dfs(int s) {
  stack<pair<int, pair<int, int>>> st;
  st.push({s, {f[0][s], 1}});
  v[s] = true;

  int maxi = f[0][s], num = 1;
  while (!st.empty()) {
    int now = st.top().first;
    int newMax = st.top().second.first;
    int newNum = st.top().second.second;
    st.pop();

    if (maxi == newMax)
      num++;
    else if (maxi < newMax) {
      maxi = newMax;
      num = 1;
    }

    for (int i = 0; i < 2; i++) {
      if (!v[b[i][now]]) {
        v[b[i][now]] = true;
        st.push({b[i][now], {f[i][now], newNum}});
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

    cout << ans << "\n";
  }
}