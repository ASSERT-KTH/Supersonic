#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(string t, int now, vector<string>& vs) {
  if (now == t.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  for (int i = 0; i < now; i++) {
    d[t[i] - 'a']++;
  }
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    string tmp = t;
    tmp[now]++;
    dfs(tmp, now + 1, vs);
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0) {
    dfs(t, now + 1, vs);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    if (s == "#") {
      break;
    }
    vector<string> vs;
    dfs(s, 0, vs);
    int ans = vs.size();
    cout << ans << endl;
    if (ans <= 10) {
      for (int i = 0; i < ans; i++) {
        cout << vs[i] << endl;
      }
    } else {
      for (int i = 0; i < 5; i++) {
        cout << vs[i] << endl;
      }
      for (int i = ans - 5; i < ans; i++) {
        cout << vs[i] << endl;
      }
    }
  }
  return 0;
}