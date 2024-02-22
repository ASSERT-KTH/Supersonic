#include <iostream>
#include <algorithm>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

const int MAX_STRINGS = 100000;
const int MAX_LENGTH = 26;

string s;
string vs[MAX_STRINGS];
int vsSize;
bool f[MAX_LENGTH];

void dfs(char t[], int now) {
  if (now == s.size()) {
    vs[vsSize++] = string(t, t + s.size());
    return;
  }
  int d[MAX_LENGTH] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    char tmp[MAX_LENGTH];
    copy(t, t + now, tmp);
    tmp[now] = t[now] + 1;
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
      
    vsSize = 0;
    char start[MAX_LENGTH];
    copy(s.begin(), s.end(), start);
    dfs(start, 0);
    
    int ans = vsSize;
    partial_sort(vs, vs + min(ans, 5), vs + ans);
    
    cout << ans << endl;
    rep(i, 0, min(ans, 5)) { cout << vs[i] << endl; }
    if (ans > 10) {
      rep(i, ans - 5, ans) { cout << vs[i] << endl; }
    }
  }
}