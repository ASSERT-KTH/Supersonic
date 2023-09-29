#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(a) (int)((a).size())

ll po[1000], ha[6000], gha[6000];
bool vis[250][1 << 12];
int len[12], n;

void solve() {
    string text;
    rep(i, n) {
        string a;
        cin >> a;
        len[i] = SZ(a);
        ll h = 0;
        for (char c : a)
            h = h * 31 + c;
        ha[i] = h;
    }
    po[0] = 1;
    rep(i, 999) po[i + 1] = po[i] * 31;
    int ans = 0;
    string a;
    cin >> a;
    text += a;
    rep(i, SZ(text)) gha[i + 1] = gha[i] * 31 + text[i];
    rep(i, 250) rep(j, 1 << n) vis[i][j] = 0;
    rep(i, 250) vis[i][0] = 1;
    rep(j, SZ(text) + 1) {
        int cur = j % 250;
        for (int i = 0; i < (1 << n); ++i) {
            if (!vis[cur][i])
                continue;
            rep(k, n) if (!(i & (1 << k)) && len[k] + j <= SZ(text) &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
                vis[(j + len[k]) % 250][i | (1 << k)] = 1;
        }
        ans += vis[cur][(1 << n) - 1];
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n && n > 0) {
        solve();
    }
    return 0;
}