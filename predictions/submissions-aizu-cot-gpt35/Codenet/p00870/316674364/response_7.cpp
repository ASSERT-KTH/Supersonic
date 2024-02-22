#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  
  vector<string> patterns(n);
  for (int i = 0; i < n; ++i) {
    cin >> patterns[i];
  }
  
  string text;
  for (int i = 0; i < m; ++i) {
    string a;
    cin >> a;
    text += a;
  }
  
  int ans = 0;
  vector<int> ha(n);
  vector<int> len(n);
  vector<int> gha(text.size() + 1);
  vector<vector<bool>> vis(1 << n, vector<bool>(text.size() + 1, false));
  
  for (int i = 0; i < n; ++i) {
    int h = 0;
    len[i] = patterns[i].size();
    for (char c : patterns[i]) {
      h = h * 31 + c;
    }
    ha[i] = h;
  }
  
  vector<int> po(text.size() + 1);
  po[0] = 1;
  for (int i = 1; i <= text.size(); ++i) {
    po[i] = po[i - 1] * 31;
  }
  
  for (int j = 0; j < text.size() + 1; ++j) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); ++i) {
      if (!vis[cur][i])
        continue;
      for (int k = 0; k < n; ++k) {
        if ((~i & (1 << k)) && len[k] + j <= text.size() &&
            ha[k] == gha[j + len[k]] - gha[j] * po[len[k]]) {
          vis[(j + len[k]) % 250][i | (1 << k)] = true;
        }
      }
    }
    ans += vis[cur][(1 << n) - 1];
    for (int i = 0; i < (1 << n); ++i) {
      vis[cur][i] = false;
    }
    vis[cur][0] = true;
  }
  
  cout << ans << endl;
}

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0)
      break;
    solve();
  }
  return 0;
}