#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const ll INF = 1e18;
vector<pair<int, ll>> g[MAXN];
ll h[MAXN], dp[MAXN][105];
int main() {
    int n, m, X;
    scanf("%d %d %d", &n, &m, &X);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    for(int i = 1; i <= m; i++) {
        int u, v; ll w;
        scanf("%d %d %lld", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= X; j++) dp[i][j] = INF;
    priority_queue<pair<ll, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(1, X)));
    while(!q.empty()) {
        ll dist = -q.top().first;
        int u = q.top().second.first, fuel = q.top().second.second;
        q.pop();
        if(dist > dp[u][fuel]) continue;
        for(auto e : g[u]) {
            int v = e.first; ll w = e.second;
            if(fuel >= w && dist < dp[v][fuel - w]) {
                dp[v][fuel - w] = dist;
                q.push(make_pair(-dp[v][fuel - w], make_pair(v, fuel - w)));
            }
        }
        if(fuel < X && dist + 1 < dp[u][fuel + 1]) {
            dp[u][fuel + 1] = dist + 1;
            q.push(make_pair(-dp[u][fuel + 1], make_pair(u, fuel + 1)));
        }
    }
    ll ans = INF;
    for(int i = 0; i <= X; i++) ans = min(ans, dp[n][i]);
    if(ans == INF) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}