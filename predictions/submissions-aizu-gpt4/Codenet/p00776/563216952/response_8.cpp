#include <bits/stdc++.h>

using namespace std;

string s;
set<string> vs;

void dfs(string t, int now) {
  if (now == s.size()) {
    vs.insert(t);
    return;
  }
  int d[26] = {};
  for (int i = 0; i < now; ++i)
    d[t[i] - 'a']++;
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
  while (cin >> s, s != "#") {
    vs.clear();
    dfs(s, 0);
    int ans = vs.size();
    cout << ans << endl;
    auto it = vs.begin();
    advance(it, min(5, ans));
    for(auto i = vs.begin(); i != it; ++i)
      cout << *i << endl;
    if(ans > 10) {
      auto it2 = vs.end();
      advance(it, -5);
      for(auto i = it2; i != it; --i)
        cout << *i << endl;
    }
  }
}