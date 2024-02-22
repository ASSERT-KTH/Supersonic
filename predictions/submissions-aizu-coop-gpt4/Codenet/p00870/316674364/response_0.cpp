#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAX_TEXT_LEN = 6000;
const int MAX_STATES = 1 << 12;
ll hash_acc[MAX_TEXT_LEN];
bool dp[250][MAX_STATES];

void solve() {
  int n, m;
  cin >> n >> m;

  vector<ll> hashes(n);
  vector<int> lengths(n);
  rep(i, n) {
    string word;
    cin >> word;
    ll h = 0;
    lengths[i] = word.size();
    for (char c : word) {
      h = h * 31 + c;
    }
    hashes[i] = h;
  }

  ll power[1000];
  power[0] = 1;
  rep(i, 999) power[i + 1] = power[i] * 31;

  int ans = 0;
  string text;
  rep(i, m) {
    string line;
    cin >> line;
    text += line;
  }
  rep(i, text.size()) hash_acc[i + 1] = hash_acc[i] * 31 + text[i];

  rep(i, 250) rep(j, MAX_STATES) dp[i][j] = 0;
  rep(i, 250) dp[i][0] = 1;

  rep(j, text.size() + 1) {
    int cur = j % 250;
    rep(i, MAX_STATES) {
      if (!dp[cur][i]) continue;
      rep(k, n) if (!(i & (1 << k)) && lengths[k] + j <= text.size() &&
          hashes[k] == hash_acc[j + lengths[k]] - hash_acc[j] * power[lengths[k]]) {
        dp[(j + lengths[k]) % 250][i | (1 << k)] = 1;
      }
    }
    ans += dp[cur][(1 << n) - 1];
    rep(i, MAX_STATES) dp[cur][i] = 0;
    dp[cur][0] = 1;
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