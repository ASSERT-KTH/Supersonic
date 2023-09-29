#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
vector<string> vs;
bool f[26];
void dfs(string t, int now, int d[]) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  if (d[t[now] - 'a'] > 0) {
    dfs(t, now + 1, d);
  }
  else {
    rep(i, t[now] - 'a' + 1, 26) {
      if (d[i] > 0) {
        char c = 'a' + i;
        string tmp = t;
        tmp[now] = c;
        dfs(tmp, now + 1, d);
      }
    }
    if (d[t[now] - 'a'] == 0) {
      d[t[now] - 'a'] = 1;
      dfs(t, now + 1, d);
      d[t[now] - 'a'] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d[26];
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    memset(d, 0, sizeof(d));
    rep(i, 0, s.size()) {
      d[s[i] - 'a']++;
    }
    dfs(s, 0, d);
    int ans = vs.size();
    sort(vs.begin(), vs.end());
    cout << ans << endl;
    if (ans <= 10) {
      rep(i, 0, ans) { cout << vs[i] << endl; }
    } else {
      rep(i, 0, 5) { cout << vs[i] << endl; }
      rep(i, ans - 5, ans) { cout << vs[i] << endl; }
    }
  }
}