#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
vector<string> vs;
bool f[26];

void dfs(string& t, int now, int d[]) {
  if (now == s.size()) {
    vs.emplace_back(t);
    return;
  }
  d[t[now] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now]++;
    dfs(t, now + 1, d);
    t[now]--;
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1, d);
  d[t[now] - 'a']--;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    vs.reserve(s.size());
    int d[26] = {};
    dfs(s, 0, d);
    sort(vs.begin(), vs.end());
    cout << vs.size() << endl;
    if (vs.size() <= 10) {
      rep(i, 0, vs.size()) { cout << vs[i] << endl; }
    } else {
      rep(i, 0, 5) { cout << vs[i] << endl; }
      rep(i, vs.size() - 5, vs.size()) { cout << vs[i] << endl; }
    }
  }
}