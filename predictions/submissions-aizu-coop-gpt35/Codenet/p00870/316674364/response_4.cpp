#include <iostream>
#include <string>
#include <vector>
using namespace std;

const double EPSILON = 1e-6;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<long long> ha(n);
    vector<int> len(n);
    for (int i = 0; i < n; ++i) {
      string a;
      cin >> a;
      long long h = 0;
      len[i] = a.size();
      for (char c : a) {
        h = h * 31 + c;
      }
      ha[i] = h;
    }
    vector<long long> gha(m + 1);
    string text;
    for (int jjj = 0; jjj < m; ++jjj) {
      string a;
      cin >> a;
      text += a;
    }
    for (int i = 0; i < m; ++i) {
      gha[i + 1] = gha[i] * 31 + text[i];
    }
    vector<vector<bool>> vis(250, vector<bool>(1 << n, false));
    for (int i = 0; i < 250; ++i) {
      vis[i][0] = true;
    }
    int ans = 0;
    for (int j = 0; j < text.size() + 1; ++j) {
      int cur = j % 250;
      for (int i = 0; i < (1 << n); ++i) {
        if (!vis[cur][i]) {
          continue;
        }
        for (int k = 0; k < n; ++k) {
          if ((~i & (1 << k)) && len[k] + j <= text.size() &&
              ha[k] == gha[j + len[k]] - gha[j] * 31LL * len[k]) {
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
  return 0;
}