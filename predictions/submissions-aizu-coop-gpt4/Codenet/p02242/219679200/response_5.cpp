#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

using uint = unsigned int;
using P = pair<uint, uint>;

const uint INF = 1e9+7;
struct edge { uint to, cost; };

vector<vector<edge>> G;
vector<uint> d;

void dijkstra(uint s) {
    priority_queue<P, vector<P>, greater<P> > que;
    d.assign(G.size(), INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        uint v = p.second;
        if(d[v] < p.first) continue;
        for(auto &e : G[v]) {
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    uint n;
    scanf("%u", &n);
    G.resize(n);
    uint u, k, c, v;
    for (uint i = 0; i < n; ++i) {
        scanf("%u %u", &u, &k);
        for (uint j = 0; j < k; ++j) {
            scanf("%u %u", &c, &v);
            G[u].push_back((edge){c, v});
        }
    }
    dijkstra(0);
    for (uint i = 0; i < n; ++i) {
        printf("%u %u\n", i, d[i]);
    }
}