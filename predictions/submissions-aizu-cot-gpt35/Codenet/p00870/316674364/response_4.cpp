#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;
ll gha[6000];
ll po[1000];

void solve() {
  vector<ll> ha(n);
  vector<int> len(n);
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (char c : a)
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
  for (int i = 0; i < text.size(); ++i)
    gha[i + 1] = gha[i] * 31 + text[i];

  vector<bool> vis(1 << n);
  vector<bool> next_vis(1 << n);
  for (int i = 0; i < 250; ++i)
    vis[0] = true;

  for (int j = 0; j < text.size() + 1; ++j) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); ++i) {
      if (!vis[i])
        continue;
      for (int k = 0; k < n; ++k) {
        if ((~i) & (1 << k) && len[k] + j <= text.size() &&
            ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          next_vis[i | (1 << k)] = true;
      }
    }
    ans += next_vis[(1 << n) - 1];
    vis = next_vis;
    fill(next_vis.begin(), next_vis.end(), false);
    vis[0] = true;
  }
  cout << ans << endl;
}

int main() {
  while (cin >> n >> m, n)
    solve();
  return 0;
}