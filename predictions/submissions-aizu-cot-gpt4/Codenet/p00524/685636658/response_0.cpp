#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using pi = struct { int first, second; };
using P = pair<ll, int>;
struct edge {
  int to;
  ll cost;
};
const int V = 100000;
const int VV = 1000000;
const ll INF = LLONG_MAX / 3;
vector<edge> G[V], gg[VV];
set<int> height[V];
int n, m;
ll X;
int H[V];
unordered_map<pi, int, hash_pair> v2id;
int max_h[V] = {};
ll d[VV];
int main() {
    scanf(" %d %d %lld", &n, &m, &X);
    rep(i, n) scanf(" %d", &H[i]);
    rep(i, m) {
        int a, b, t;
        scanf(" %d %d %d", &a, &b, &t);
        --a;
        --b;
        G[a].push_back({b, t});
        G[b].push_back({a, t});
    }
    int ct = 1;
    priority_queue<pi> que;
    que.push({X, 0});
    v2id[{0, X}] = 0;
    max_h[0] = X;
    height[0].insert(X);
    while (!que.empty()) {
        pi p = que.top();
        que.pop();
        int v = p.second, h = p.first;
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
                pi vbh = {v, bh};
                pi etonh = {e.to, nh};
                if (!v2id.count(vbh)) {
                    v2id[vbh] = ct++;
                    height[v].insert(bh);
                }
                if (!v2id.count(etonh)) {
                    v2id[etonh] = ct++;
                    height[e.to].insert(nh);
                }
                int uu = v2id[vbh], vv = v2id[etonh];
                gg[uu].push_back({vv, e.cost});
                max_h[e.to] = nh;
                que.push({max_h[e.to], e.to});
            }
        }
    }
    rep(i, n) for (const auto &e : G[i]) {
        if (H[i] < e.cost)
            continue;
        pi iecost = {i, e.cost};
        pi eto0 = {e.to, 0};
        if (!v2id.count(iecost)) {
            v2id[iecost] = ct++;
            height[i].insert(e.cost);
        }
        if (!v2id.count(eto0)) {
            v2id[eto0] = ct++;
            height[e.to].insert(0);
        }
        int uu = v2id[iecost];
        int vv = v2id[eto0];
        gg[uu].push_back({vv, e.cost});
    }
    pi n1Hn1 = {n - 1, H[n - 1]};
    if (!v2id.count(n1Hn1)) {
        v2id[n1Hn1] = ct++;
        height[n - 1].insert(H[n - 1]);
    }
    rep(i, n) {
        int S = height[i].size();
        auto itr = height[i].begin();
        rep(j, S - 1) {
            auto nx = itr;
            ++nx;
            int uu = v2id[{i, *itr}];
            int vv = v2id[{i, *nx}];
            int dist = *nx - *itr;
            gg[uu].push_back({vv, dist});
            gg[vv].push_back({uu, dist});
            itr = nx;
        }
    }
    int start = v2id[{0, X}];
    int goal = v2id[n1Hn1];
    fill(d, d + VV, INF);
    d[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        P now = pq.top();
        pq.pop();
        int v = now.second;
        if (now.first > d[v])
            continue;
        for (const auto &e : gg[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                pq.push({d[e.to], e.to});
            }
        }
    }
    ll ans = d[goal];
    if (ans == INF)
        ans = -1;
    printf("%lld\n", ans);
    return 0;
}