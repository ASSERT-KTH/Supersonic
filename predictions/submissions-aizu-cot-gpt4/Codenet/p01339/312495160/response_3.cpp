#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007LL
#define EPS 1e-9
#define INF 1070000000LL

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

int N, M;
vi g[1010], r[1010];
int used[1010];
int List[1010], l;
int cycle[1010], c;
int inCycle[1010];
ll dp[1010] = {-1};

void dfs(int cur) {
    if (used[cur]) {
        int from = 0;
        while (List[from] != cur)
            from++;
        for (int i = from; i < l; i++) { cycle[c++] = List[i]; }
        return;
    }
    used[cur] = 1;
    List[l++] = cur;
    if (g[cur].empty()) {
        cycle[c++] = cur;
        return;
    }
    for (int i = 0; i < g[cur].size(); i++) { dfs(g[cur][i]); }
}

ll fastMod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll solve(int v) {
    ll &res = dp[v];
    if (res != -1)
        return res;
    used[v] = 1;
    res = 1;
    int sz = r[v].size();
    for (int i = 0; i < sz; i++) { res = fastMod(res, solve(r[v][i]), MOD); }
    res = (res + 1) % MOD;
    return res;
}

ll f(int start) {
    l = 0;
    c = 0;
    dfs(start);
    ll res = 1;
    for (int i = 0; i < c; i++) inCycle[cycle[i]] = 1;
    int sz = r[cycle[0]].size();
    for (int i = 0; i < c; i++) 
        for (int j = 0; j < sz; j++) {
            if (inCycle[r[cycle[i]][j]])
                continue;
            res = fastMod(res, solve(r[cycle[i]][j]), MOD);
        }
    res = (res + 1) % MOD;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        g[s].push_back(d);
        r[d].push_back(s);
    }
    ll ans = 1;
    for (int i = 0; i < N; i++) if (!used[i]) { ans = fastMod(ans, f(i), MOD); }
    cout << ans << endl;
}