#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PI;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll po[1000];
void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> ha(n);
  vector<int> len(n);
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for(char c : a)
      h = h * 31 + c;
    ha[i] = h;
  }
  po[0] = 1;
  rep(i, 999) po[i + 1] = po[i] * 31;
  int ans = 0;
  string text;
  rep(j, m) {
    string a;
    cin >> a;
    text += a;
  }
  vector<ll> gha(text.size() + 1);
  rep(i, text.size()) gha[i + 1] = gha[i] * 31 + text[i];
  vector<vector<bool>> vis(250, vector<bool>(1 << n));
  rep(i, 250) vis[i][0] = 1;
  rep(j, text.size() + 1) {
    int cur = j % 250;
    rep(i, 1 << n) {
      if (!vis[cur][i])
        continue;
      rep(k, n) if ((~i & (1 << k)) && len[k] + j <= text.size() &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, 1 << n) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  cout << ans << endl;
  return;
}

int main(int argc, char *argv[]) {
  int n, m;
  while (cin >> n >> m, n)
    solve();
  return 0;
}