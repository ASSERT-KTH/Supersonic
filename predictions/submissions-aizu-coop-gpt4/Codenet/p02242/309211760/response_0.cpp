#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

typedef pair<int, int> P;

int n;
vector<Edge> G[MAX];
int color[MAX], d[MAX];

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> PQ;

    for(int i = 0; i < n; i++) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    PQ.push(P(0, 0));
    color[0] = GRAY;

    while(!PQ.empty()) {
        P f = PQ.top(); PQ.pop();
        int u = f.second;
        color[u] = BLACK;

        if(d[u] < f.first) 
            continue;

        for(auto &e : G[u]) {
            if(color[e.v] == BLACK)
                continue;
            if(d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                PQ.push(P(d[e.v], e.v));
                color[e.v] = GRAY;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int k, c, u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> k;
        for(int j = 0; j < k; j++) {
            cin >> v >> c;
            G[u].push_back(Edge(v, c));
        }
    }
    dijkstra();
    return 0;
}