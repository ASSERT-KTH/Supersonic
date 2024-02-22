#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vs;

void dfs(string& t, int now) {
  if (now == t.size()) {
    vs.push_back(t);
    return;
  }
  
  if (t[now] != 'z' && t.find(t[now] + 1, 0) == string::npos) {
    t[now]++;
    dfs(t, now + 1);
    t[now]--;
  }
  
  dfs(t, now + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  while (1) {
    cin >> s;
    if (s == "#")
      break;
      
    vs.clear();
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
  
  return 0;
}