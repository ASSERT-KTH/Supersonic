#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
set<string> vs;
bool f[26];
void dfs(string t, int now) {
  if (now == s.size()) {
    vs.insert(t);
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
    cout << ans << endl;
    auto it = vs.begin();
    if (ans <= 10) {
      rep(i, 0, ans) { 
         cout << *it++ << endl; 
      }
    } else {
      rep(i, 0, 5) { 
         cout << *it++ << endl; 
      }
      it = prev(vs.end(), 5);
      rep(i, ans - 5, ans) { 
         cout << *it++ << endl; 
      }
    }
  }
}