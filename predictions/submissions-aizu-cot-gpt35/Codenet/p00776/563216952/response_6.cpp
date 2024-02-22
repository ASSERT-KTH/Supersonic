#include <iostream>
#include <string>
#include <set>

using namespace std;

bool f[26];

void dfs(string t, int now, set<string>& result) {
  if (now == t.size()) {
    result.insert(t);
    return;
  }
  
  int d[26] = {};
  for (int i = 0; i < now; i++) {
    d[t[i] - 'a']++;
  }
  
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    dfs(tmp, now + 1, result);
  }
  
  if (t[now] == 'a' || d[t[now] - 'a'] != 0) {
    dfs(t, now + 1, result);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  while (getline(cin, s) && s != "#") {
    set<string> result;
    dfs(s, 0, result);
    
    cout << result.size() << endl;
    
    for (const string& str : result) {
      cout << str << endl;
    }
  }
  
  return 0;
}