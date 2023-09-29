#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
vector<string> vs;
bool f[26];
void dfs(string t, int now, int *d) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  int new_d[26];
  memcpy(new_d, d, sizeof(new_d));
  rep(i, 0, now) new_d[t[i] - 'a']++;
  if (t[now] != 'z' && new_d[t[now] + 1 - 'a'] == 0) {
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    dfs(tmp, now + 1, new_d);
  }
  if (t[now] == 'a' || new_d[t[now] - 'a'] != 0)
    dfs(t, now + 1, new_d);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    int d[26] = {};
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