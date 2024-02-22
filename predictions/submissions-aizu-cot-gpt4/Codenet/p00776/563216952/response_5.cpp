#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

bool f[26];

void dfs(string &t, int now) {
  if (now == t.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    dfs(t, now + 1);
    t[now] = t[now] - 1; // reset the change
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s, s != "#") {
    vector<string> vs;
    dfs(s, 0);
    int ans = vs.size();
    cout << ans << endl;
    if (ans <= 10) {
      for (const auto &str : vs) { cout << str << endl; }
    } else {
      rep(i, 0, 5) { cout << vs[i] << endl; }
      rep(i, ans - 5, ans) { cout << vs[i] << endl; }
    }
  }
}