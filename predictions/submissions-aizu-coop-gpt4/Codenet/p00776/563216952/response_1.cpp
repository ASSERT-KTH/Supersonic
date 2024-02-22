#include <bits/stdc++.h>
using namespace std;

string s;
set<string> vs;
int d[26] = {};

void dfs(string& t, int now) {
  if (now == s.size()) {
    vs.insert(t);
    return;
  }
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    d[t[now] - 'a']--;
    t[now] = t[now] + 1;
    d[t[now] - 'a']++;
    dfs(t, now + 1);
    d[t[now] - 'a']--;
    t[now] = t[now] - 1;
    d[t[now] - 'a']++;
  }
  if (t[now] == 'a' || d[t[now] - 1 - 'a'] != 0) {
    dfs(t, now + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    memset(d, 0, sizeof(d));
    dfs(s, 0);
    int ans = vs.size();
    cout << ans << endl;
    if (ans <= 10) {
      for (const string& str : vs) {
        cout << str << "\n";
      }
    } else {
      auto it = vs.begin();
      for (int i = 0; i < 5; ++i) {
        cout << *it << "\n";
        ++it;
      }
      it = prev(vs.end(), 5);
      for (int i = 0; i < 5; ++i) {
        cout << *it << "\n";
        ++it;
      }
    }
  }
  return 0;
}