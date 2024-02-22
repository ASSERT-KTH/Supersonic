#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

using ll = long long;

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define pb push_back
#define fi first
#define se second

using pi = pair<int, int>;
using P = pair<ll, int>;

struct edge {
    int to;
    ll cost;
};

const int V = 100000;
const int VV = 1000000;
const ll INF = LLONG_MAX / 3;

vector<edge> G[V], gg[VV];
vector<int> height[V];
int n, m;
ll X;
int H[V];
vector<int> v2id;
int max_h[V] = {};
ll d[VV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> X;
    rep(i, n) cin >> H[i];

    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        --a;
        --b;
        G[a].emplace_back(edge{b, t});
        G[b].emplace_back(edge{a, t});
    }

    int ct = 1;
    priority_queue<pi> que;
    que.emplace(X, 0);
    v2id.emplace_back(0);
    max_h[0] = X;
    height[0].push_back(X);

    while (!que.empty()) {
        pi p = que.top();
        que.pop();
        int v = p.se, h = p.fi;
        if (h < max_h[v])
            continue;
        for (const auto &e : G[v]) {
            int bh = h;
            int nh = h - e.cost;
            if (nh < 0)
                continue;
            if (nh > H[e.to]) {
                bh = H[e.to] + e.cost;
                nh = H[e.to];
            }
            if (nh > max_h[e.to]) {
                if (v2id.size() <= ct) {
                    v2id.emplace_back(ct);
                    height[v].push_back(bh);
                }
                if (v2id.size() <= ct) {
                    v2id.emplace_back(ct);
                    height[e.to].push_back(nh);
                }
                int uu = v2id[v * V + bh];
                int vv = v2id[e.to * V + nh];
                gg[uu].emplace_back(edge{vv, e.cost});
                max_h[e.to] = nh;
                que.emplace(max_h[e.to], e.to);
                ct++;
            }
        }
    }

    rep(i, n) {
        for (const auto &e : G[i]) {
            if (H[i] < e.cost)
                continue;
            if (v2id.size() <= ct) {
                v2id.emplace_back(ct);
                height[i].push_back(e.cost);
            }
            if (v2id.size() <= ct) {
                v2id.emplace_back(ct);
                height[e.to].push_back(0);
            }
            int uu = v2id[i * V + e.cost];
            int vv = v2id[e.to * V + 0];
            gg[uu].emplace_back(edge{vv, e.cost});
            ct++;
        }
    }

    if (v2id.size() <= ct) {
        v2id.emplace_back(ct);
        height[n - 1].push_back(H[n - 1]);
    }

    rep(i, n) {
        int S = height[i].size();
        auto itr = height[i].begin();
        rep(j, S - 1) {
            auto nx = itr;
            ++nx;
            assert(v2id.size() > i * V + *itr);
            assert(v2id.size() > i * V + *nx);
            int uu = v2id[i * V + *itr];
            int vv = v2id[i * V + *nx];
            int dist = *nx - *itr;
            gg[uu].emplace_back(edge{vv, dist});
            gg[vv].emplace_back(edge{uu, dist});
            itr = nx;
        }
    }

    int start = v2id[0 * V + X];
    int goal = v2id[(n - 1) * V + H[n - 1]];

    fill(d, d + VV, INF);
    d[start] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if (now.fi > d[v])
            continue;
        for (const auto &e : gg[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                pq.emplace(d[e.to], e.to);
            }
        }
    }

    ll ans = d[goal];
    if (ans == INF)
        ans = -1;

    cout << ans << "\n";

    return 0;
}