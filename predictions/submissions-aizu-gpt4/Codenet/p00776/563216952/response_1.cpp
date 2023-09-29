#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;

void dfs(string t, int now, vector<string>& vs) {
  if (now == s.size()) {
    vs.emplace_back(t);
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    dfs(t, now + 1, vs);
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1, vs);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    cin >> s;
    if (s == "#") break;
    vector<string> vs;
    dfs(s, 0, vs);
    int ans = vs.size();
    nth_element(vs.begin(), vs.begin()+min(5, ans), vs.end());
    nth_element(vs.begin()+max(ans-5,0), vs.end()-1, vs.end());
    cout << ans << '\n';
    if (ans <= 10) {
      rep(i, 0, ans) { cout << vs[i] << '\n'; }
    } else {
      rep(i, 0, 5) { cout << vs[i] << '\n'; }
      rep(i, ans - 5, ans) { cout << vs[i] << '\n'; }
    }
  }
  return 0;
}