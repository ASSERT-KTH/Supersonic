#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }
  string text;
  for (int i = 0; i < m; i++) {
    string a;
    cin >> a;
    text += a;
  }
  int ans = 0;
  vector<int> ha(n);
  vector<int> len(n);
  for (int i = 0; i < n; i++) {
    len[i] = words[i].size();
    for (char c : words[i]) {
      ha[i] = ha[i] * 31 + c;
    }
  }
  vector<vector<bool>> vis(250, vector<bool>(1 << n, false));
  vector<int> gha(text.size() + 1, 0);
  vector<int> po(1000, 1);
  for (int i = 1; i < 1000; i++) {
    po[i] = po[i - 1] * 31;
  }
  for (int i = 1; i <= text.size(); i++) {
    gha[i] = gha[i - 1] * 31 + text[i - 1];
  }
  for (int j = 0; j <= text.size(); j++) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); i++) {
      if (!vis[cur][i]) continue;
      for (int k = 0; k < n; k++) {
        if ((~i & (1 << k)) && len[k] + j <= text.size() &&
            ha[k] == gha[j + len[k]] - gha[j] * po[len[k]]) {
          vis[(j + len[k]) % 250][i | (1 << k)] = true;
        }
      }
    }
    ans += vis[cur][(1 << n) - 1];
    for (int i = 0; i < (1 << n); i++) {
      vis[cur][i] = false;
    }
    vis[cur][0] = true;
  }
  cout << ans << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    solve();
  }
  return 0;
}