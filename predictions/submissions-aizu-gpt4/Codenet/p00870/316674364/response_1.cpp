#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAX_N = 6000;
ll gha[MAX_N], po[MAX_N];
bool vis[250][1 << 12];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> ha(n);
  vector<int> len(n);
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (char c : a) h = h * 31 + c;
    ha[i] = h;
  }
  po[0] = 1;
  for (int i = 0; i < 999; ++i) po[i + 1] = po[i] * 31;

  int ans = 0;
  string text;
  for (int jjj = 0; jjj < m; ++jjj) {
    string a;
    cin >> a;
    text += a;
  }
  for (int i = 0; i < text.size(); ++i) gha[i + 1] = gha[i] * 31 + text[i];

  for (int i = 0; i < 250; ++i) 
    for (int j = 0; j < (1 << n); ++j) vis[i][j] = 0;
  for (int i = 0; i < 250; ++i) vis[i][0] = 1;

  for (int j = 0; j <= text.size(); ++j) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); ++i) {
      if (!vis[cur][i]) continue;
      for (int k = 0; k < n; ++k) 
        if ((~i & (1 << k)) && len[k] + j <= text.size() &&
            ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    for (int i = 0; i < (1 << n); ++i) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  cout << ans << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n) solve();
  return 0;
}