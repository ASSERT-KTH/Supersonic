#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

const int MAXN = 15;
string s;
vector<string> vs;
bool f[26];
int d[MAXN], vis[MAXN];
char ans[MAXN];

void dfs(int now, int len) {
  if (now == len) {
    vs.push_back(ans);
    return;
  }
  rep(i, 0, 26) {
    if (!f[i] && (!i || !vis[i - 1])) {
      f[i] = true;
      ans[now] = i + 'a';
      dfs(now + 1, len);
      f[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    int len = s.length();
    memset(d, 0, sizeof(d));
    rep(i, 0, len) d[s[i] - 'a']++;
    dfs(0, len);
    sort(vs.begin(), vs.end());
    int cnt = 0;
    for (auto &str : vs) {
      if (str == s)
        break;
      cnt++;
    }
    cout << cnt << endl;
    for (int i = max(0, cnt - 5); i < min((int)vs.size(), cnt + 5); i++)
      cout << vs[i] << endl;
  }
  return 0;
}