#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
set<string> vs;
int d[26] = {};

void dfs(string t, int now) {
  if (now == s.size()) {
    vs.insert(t);
    return;
  }
  d[t[now] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    dfs(tmp, now + 1);
  }
  if (t[now] == 'a' || d[t[now] - 1 - 'a'] != 0)
    dfs(t, now + 1);
  d[t[now] - 'a']--;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    if (s.length() > 26) { // Maximum possible permutations with unique characters is 26!.
      cout << "Input too long" << endl;
      continue;
    }
    vs.clear();
    memset(d, 0, sizeof(d));
    dfs(s, 0);
    int ans = vs.size();
    cout << ans << endl;
    auto it = vs.begin();
    if (ans <= 10) {
      for(auto it = vs.begin(); it != vs.end(); ++it)
        cout << *it << endl;
    } else {
      rep(i, 0, 5) { cout << *it++ << endl; }
      it = std::prev(vs.end(), 5);
      rep(i, 0, 5) { cout << *it++ << endl; }
    }
  }
}