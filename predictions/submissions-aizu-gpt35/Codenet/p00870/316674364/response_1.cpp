#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;

int n, m;
ll gha[6000];
ll po[1000];
vector<int> len;
vector<ll> ha;

void solve() {
  len.resize(n);
  ha.resize(n);
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (auto c : a)
      h = h * 31 + c;
    ha[i] = h;
  }
  po[0] = 1;
  for (int i = 0; i < 999; ++i)
    po[i + 1] = po[i] * 31;
  int ans = 0;
  string text;
  for (int jjj = 0; jjj < m; ++jjj) {
    string a;
    cin >> a;
    text += a;
  }
  for (int i = 0; i <= text.size(); ++i)
    gha[i + 1] = gha[i] * 31 + text[i];
  bool vis[250][1 << n];
  for (int i = 0; i < 250; ++i)
    for (int j = 0; j < (1 << n); ++j)
      vis[i][j] = false;
  for (int i = 0; i < 250; ++i)
    vis[i][0] = true;
  for (int j = 0; j <= text.size(); ++j) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); ++i) {
      if (!vis[cur][i])
        continue;
      for (int k = 0; k < n; ++k)
        if ((~i & (1 << k)) && len[k] + j <= text.size() &&
            ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = true;
    }
    ans += vis[cur][(1 << n) - 1];
    for (int i = 0; i < (1 << n); ++i)
      vis[cur][i] = false;
    vis[cur][0] = true;
  }
  cout << ans << endl;
  return;
}

int main() {
  while (cin >> n >> m, n)
    solve();
  return 0;
}