#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;

const int MAX_V = 100000;
const int MAX_VV = 1000000;
const ll INF = LLONG_MAX / 3;

int n, m;
ll X;
int H[MAX_V];
map<pi, int> v2id;
ll d[MAX_VV];
int max_h[MAX_V] = {};
vector<pair<int, ll>> G[MAX_V], gg[MAX_VV];
set<int> height[MAX_V];

void dijkstra(int start, int goal) {
    fill(d, d + MAX_VV, INF);
    d[start] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(pli(0, start));
    while (!pq.empty()) {
        pli now = pq.top(); pq.pop();
        int v = now.second;
        if (now.first > d[v]) continue;
        for (const auto &e : gg[v]) {
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v] + e.second;
                pq.push(pli(d[e.first], e.first));
            }
        }
    }
}

void build_graph() {
    int ct = 1;
    priority_queue<pi, vector<pi>, greater<pi>> que;
    que.push(pi(0, X));
    v2id[pi(0, X)] = 0;
    max_h[0] = X;
    height[0].insert(X);
    while (!que.empty()) {
        pi p = que.top(); que.pop();
        int v = p.second, h = p.first;
        if (h < max_h[v]) continue;
        for (const auto &e : G[v]) {
            int bh = h;
            int nh = h - e.second;
            if (nh < 0) continue;
            if (nh > H[e.first]) {
                bh = H[e.first] + e.second;
                nh = H[e.first];
            }
            if (nh > max_h[e.first]) {
                if (!v2id.count(pi(v, bh))) {
                    v2id[pi(v, bh)] = ct++;
                    height[v].insert(bh);
                }
                if (!v2id.count(pi(e.first, nh))) {
                    v2id[pi(e.first, nh)] = ct++;
                    height[e.first].insert(nh);
                }
                int uu = v2id[pi(v, bh)], vv = v2id[pi(e.first, nh)];
                gg[uu].push_back({vv, e.second});
                max_h[e.first] = nh;
                que.push(pi(e.first, max_h[e.first]));
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (const auto &e : G[i]) {
            if (H[i] < e.second) continue;
            if (!v2id.count(pi(i, e.second))) {
                v2id[pi(i, e.second)] = ct++;
                height[i].insert(e.second);
            }
            if (!v2id.count(pi(e.first, 0))) {
                v2id[pi(e.first, 0)] = ct++;
                height[e.first].insert(0);
            }
            int uu = v2id[pi(i, e.second)];
            int vv = v2id[pi(e.first, 0)];
            gg[uu].push_back({vv, e.second});
        }
    }
    for (int i=0; i<n; i++) {
        auto itr = height[i].begin();
        while (next(itr) != height[i].end()) {
            auto nx = next(itr);
            int uu = v2id[pi(i, *itr)];
            int vv = v2id[pi(i, *nx)];
            int dist = *nx - *itr;
            gg[uu].push_back({vv, dist});
            gg[vv].push_back({uu, dist});
            itr = nx;
        }
    }
}

int main() {
    scanf(" %d %d %lld", &n, &m, &X);
    for (int i=0; i<n; i++) scanf(" %d", &H[i]);
    for (int i=0; i<m; i++) {
        int a, b, t;
        scanf(" %d %d %d", &a, &b, &t);
        a--; b--;
        G[a].push_back({b, t});
        G[b].push_back({a, t});
    }
    build_graph();
    if (!v2id.count(pi(n - 1, H[n - 1]))) {
        v2id[pi(n - 1, H[n - 1])] = v2id.size();
        height[n - 1].insert(H[n - 1]);
    }
    int start = v2id[pi(0, X)];
    int goal = v2id[pi(n - 1, H[n - 1])];
    dijkstra(start, goal);
    ll ans = d[goal];
    if (ans == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}