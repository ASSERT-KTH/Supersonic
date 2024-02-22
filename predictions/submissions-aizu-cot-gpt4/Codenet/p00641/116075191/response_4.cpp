#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAXN 100100
#define MOD 10007

short n;
vector<short> b[2][MAXN], f[2][MAXN], dp[MAXN];
bool v[MAXN];

short dfs(short s) {
  stack<short> stk;
  stk.push(s);
  short num = 1, maxi = f[0][s];

  while (!stk.empty()) {
    short now = stk.top(); stk.pop();
    v[now] = true;

    for (short i = 0; i < 2; i++) {
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
    for (short i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }

    short ans = 1;
    for (short i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i)) % MOD;
      }
    }

    cout << ans << endl;
  }

  return 0;
}