#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
vector<string> vs;
void dfs(string t, int now) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    dfs(tmp, now + 1);
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    dfs(s, 0);
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
