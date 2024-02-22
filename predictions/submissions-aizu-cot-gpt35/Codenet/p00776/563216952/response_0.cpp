#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> vs;

void dfs(string& t, int now, vector<int>& d) {
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    d[t[now] - 'a']++;
    dfs(t, now + 1, d);
    t[now] = t[now] - 1;
    d[t[now] - 'a']--;
  }
  
  if (t[now] == 'a' || d[t[now] - 'a'] != 0) {
    dfs(t, now + 1, d);
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
    vector<int> d(26, 0);
    dfs(s, 0, d);
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