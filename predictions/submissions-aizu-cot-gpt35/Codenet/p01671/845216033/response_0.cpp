#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

struct UnionFind {
    std::vector<int> data;

    UnionFind(int sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (data[x] > data[y])
            std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if (data[k] < 0)
            return k;
        return data[k] = find(data[k]);
    }

    int size(int k) {
        return -data[find(k)];
    }
};

struct edge1 {
    int u, v, cost, idx;

    bool operator<(const edge1 &e) const {
        return cost < e.cost;
    }
};

struct edge2 {
    int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
std::vector<edge1> edges;
bool killed[200000];
std::vector<edge2> tree[100000], g[100000];
long long all, ans[200000];
std::set<std::pair<int, int>> component[100000];

void rec(int idx, int par = -1) {
    for (auto &e : g[idx]) {
        component[idx].emplace(e.cost, e.idx);
    }
    for (auto &e : tree[idx]) {
        if (e.to == par)
            continue;
        rec(e.to, idx);
        auto &u = component[idx], &v = component[e.to];
        if (!v.empty()) {
            ans[e.idx] = all;
            ans[e.idx] -= e.cost;
            ans[e.idx] += v.begin()->first;
        }
        if (u.size() < v.size()) {
            std::vector<int> count_u(N), count_v(N);
            for (const auto &p : u) {
                count_u[p.second]++;
            }
            for (const auto &p : v) {
                count_v[p.second]++;
            }
            for (const auto &p : v) {
                if (count_u[p.second] > 0) {
                    count_u[p.second]--;
                } else {
                    u.emplace(p);
                }
            }
            v.clear();
        } else {
            std::vector<int> count_u(N), count_v(N);
            for (const auto &p : u) {
                count_u[p.second]++;
            }
            for (const auto &p : v) {
                count_v[p.second]++;
            }
            for (const auto &p : u) {
                if (count_v[p.second] > 0) {
                    count_v[p.second]--;
                } else {
                    v.emplace(p);
                }
            }
            u.clear();
            std::swap(u, v);
        }
    }
}

int main() {
    std::scanf("%d %d", &N, &M);
    edges.reserve(M);
    for (int i = 0; i < M; i++) {
        std::scanf("%d %d %d", &A[i], &B[i], &C[i]);
        --A[i], --B[i];
        edges.emplace_back(edge1{A[i], B[i], C[i], i});
    }
    UnionFind uf(N);
    std::sort(edges.begin(), edges.end());
    for (const auto &e : edges) {
        if (uf.unite(e.v, e.u)) {
            killed[e.idx] = true;
            all += e.cost;
        }
    }
    if (uf.size(0) != N) {
        for (int i = 0; i < M; i++) {
            std::printf("-1\n");
        }
        return 0;
    }
    for (int i = 0; i < M; i++) {
        if (killed[i]) {
            tree[A[i]].emplace_back(edge2{B[i], C[i], i});
            tree[B[i]].emplace_back(edge2{A[i], C[i], i});
            ans[i] = -1;
        } else {
            g[A[i]].emplace_back(edge2{B[i], C[i], i});
            g[B[i]].emplace_back(edge2{A[i], C[i], i});
            ans[i] = all;
        }
    }
    rec(0);
    for (int i = 0; i < M; i++) {
        std::printf("%lld\n", ans[i]);
    }
    return 0;
}