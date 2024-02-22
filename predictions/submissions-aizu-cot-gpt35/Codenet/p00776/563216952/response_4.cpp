#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> vs;
bool f[26];

void dfs(string t, int now) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  if (t[now] != 'z' && !f[t[now] + 1 - 'a']) {
    f[t[now] + 1 - 'a'] = true;
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    dfs(tmp, now + 1);
    f[t[now] + 1 - 'a'] = false;
  }
  if (t[now] == 'a' || f[t[now] - 'a']) {
    dfs(t, now + 1);
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
    fill(f, f + 26, false);
    dfs(s, 0);
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
}