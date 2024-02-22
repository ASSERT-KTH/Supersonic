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
#include <sstream>

typedef long long ll;
typedef std::pair<int, int> PI;

ll gha[6000];
ll po[1000];

void solve(int n, int m, ll *gha) {
  ll ha[n];
  int len[n];
  for (int i = 0; i < n; ++i) {
    std::string a;
    std::cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (char it : a)
      h = h * 31 + it;
    ha[i] = h;
  }
  po[0] = 1;
  for (int i = 0; i < 999; i++) po[i + 1] = po[i] * 31;
  int ans = 0;
  std::string text;
  for (int jjj = 0; jjj < m; jjj++) {
    std::string a;
    std::cin >> a;
    text += a;
  }
  for (int i = 0; i < text.size(); i++) gha[i + 1] = gha[i] * 31 + text[i];
  bool vis[250][1 << n];
  for (int i = 0; i < 250; i++) for (int j = 0; j < (1 << n); j++) vis[i][j] = 0;
  for (int i = 0; i < 250; i++) vis[i][0] = 1;
  for (int j = 0; j < text.size() + 1; j++) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); i++) {
      if (!vis[cur][i])
        continue;
      for (int k = 0; k < n; k++) {
        if ((~i & (1 << k)) && len[k] + j <= text.size() && ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
      }
    }
    ans += vis[cur][(1 << n) - 1];
    for (int i = 0; i < (1 << n); i++) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  std::cout << ans << std::endl;
  return;
}

int main(int argc, char *argv[]) {
  int n, m;
  while (std::cin >> n >> m, n)
    solve(n, m, gha);
  return 0;
}