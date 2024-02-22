#include <iostream>
#include <string>
#include <vector>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
vector<string> vs;
void dfs(string& t, int now) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  char originalChar = t[now];
  if (originalChar != 'z' && d[originalChar + 1 - 'a'] == 0) {
    t[now] = originalChar + 1;
    dfs(t, now + 1);
    t[now] = originalChar; // revert back to original character
  }
  if (originalChar == 'a' || d[originalChar - 'a'] != 0)
    dfs(t, now + 1);
}
int main() {
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    dfs(s, 0);
    int ans = vs.size();
    if (ans > 10)
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