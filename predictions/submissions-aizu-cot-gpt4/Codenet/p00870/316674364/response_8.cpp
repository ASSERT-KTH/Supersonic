#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
#define EPS (1e-6)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) rep(i, n)
#define min3(a, b, c) min((a), min((b), (c)))
#define min4(a, b, c, d) min((a), min3((b), (c), (d)))
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) a.rbegin(), a.rend()
#define CLR(a) memset((a), 0, sizeof(a))
#define FOR(it, a) for (decltype(a.begin()) it = (a).begin(); it != a.end(); ++it)
#define FORR(it, a) for (decltype(a.rbegin()) it = (a).rbegin(); it != a.rend(); ++it)
#define s2i(a) stoi(a)
#define TOP 0
#define BTM 1
#define LFT 2
#define RGT 3
#define FRT 4
#define BCK 5
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
int dxdy2ce[] = {RGT, FRT, LFT, BCK};
ll po[1000];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  vector<ll> ha(n);
  vector<int> len(n);
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = SZ(a);
    FOR(it, a)
    h = h * 31 + *it;
    ha[i] = h;
  }
  
  po[0] = 1;
  rep(i, 999) po[i + 1] = po[i] * 31;
  int ans = 0;
  string text;
  vector<ll> gha(6000);
  rep(jjj, m) {
    string a;
    cin >> a;
    text += a;
  }
  
  rep(i, SZ(text)) gha[i + 1] = gha[i] * 31 + text[i];
  vector<vector<bool>> vis(250, vector<bool>(1 << n, 0));
  rep(i, 250) vis[i][0] = 1;
  rep(j, SZ(text) + 1) {
    int cur = j % 250;
    rep(i, 1 << n) {
      if (!vis[cur][i])
        continue;
      rep(k, n) if ((~i & (1 << k)) && len[k] + j <= SZ(text) &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, 1 << n) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  printf("%d\n", ans);
}

int main(int argc, char *argv[]) {
  int n, m;
  while (scanf("%d%d", &n, &m), n)
    solve();
  return 0;
}