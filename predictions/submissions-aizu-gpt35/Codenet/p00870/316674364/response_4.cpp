#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1001, MAXM = 250001;
ll ha[MAXN], gha[MAXM], po[MAXN];
int len[MAXN], n, m;
bool vis[MAXM];
void solve() {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        len[i] = s.size();
        for (int j = 0; j < len[i]; j++) {
            ha[i] = ha[i] * 31 + s[j];
        }
    }
    po[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        po[i] = po[i - 1] * 31;
    }
    string text;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        text += s;
    }
    int ans = 0;
    int tlen = text.size();
    int blocksize = sqrt(tlen);
    for (int i = 0; i <= tlen - blocksize; i++) {
        ll h = 0;
        for (int j = i; j < i + blocksize; j++) {
            h = h * 31 + text[j];
        }
        gha[i] = h;
        vis[i] = false;
    }
    vis[tlen] = false;
    for (int i = 0; i <= tlen - blocksize; i++) {
        for (int j = 0; j < n; j++) {
            if (len[j] > blocksize) {
                continue;
            }
            if (i + len[j] > tlen) {
                continue;
            }
            ll h = 0;
            for (int k = i; k < i + len[j]; k++) {
                h = h * 31 + text[k];
            }
            if (h == ha[j]) {
                vis[i] = true;
                break;
            }
        }
    }
    for (int i = 0; i <= tlen - blocksize; i++) {
        if (!vis[i]) {
            continue;
        }
        for (int j = i + blocksize; j <= tlen; j++) {
            if (j - i > blocksize) {
                break;
            }
            gha[j] = gha[j - 1] * 31 + text[j - 1];
            if (j - i < blocksize) {
                continue;
            }
            bool found = true;
            for (int k = 0; k < n; k++) {
                if (len[k] > blocksize) {
                    continue;
                }
                ll h = 0;
                for (int l = i; l < i + len[k]; l++) {
                    h = h * 31 + text[l];
                }
                if (h != ha[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    while (cin >> n >> m, n) {
        solve();
    }
    return 0;
}