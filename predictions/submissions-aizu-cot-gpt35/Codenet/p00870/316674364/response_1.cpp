#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  string text;
  for (int i = 0; i < m; i++) {
    string a;
    cin >> a;
    text += a;
  }

  vector<ll> gha(text.size() + 1, 0);
  for (int i = 0; i < text.size(); i++) {
    gha[i + 1] = gha[i] * 31 + text[i];
  }

  vector<ll> ha(n);
  vector<int> len(n);
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    len[i] = a.size();
    for (char c : a) {
      ha[i] = ha[i] * 31 + c;
    }
  }

  vector<vector<bool>> vis(250, vector<bool>(1 << n, false));
  for (int i = 0; i < 250; i++) {
    vis[i][0] = true;
  }

  for (int j = 0; j < text.size() + 1; j++) {
    int cur = j % 250;
    for (int i = 0; i < (1 << n); i++) {
      if (!vis[cur][i]) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        if ((~i & (1 << k)) && len[k] + j <= text.size() &&
            ha[k] == gha[j + len[k]] - gha[j] * 31) {
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
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }
    solve();
  }
  return 0;
}