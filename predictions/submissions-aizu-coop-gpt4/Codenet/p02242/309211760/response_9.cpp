#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define MAX 100
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

typedef pair<int, int> P;
vector<P> adj[MAX];
int n;

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> PQ;
    int color[MAX];
    int d[MAX];
    for(int i=0; i<n; i++) {
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
        if(d[u]<f.first) continue;
        for(auto j=adj[u].begin(); j!=adj[u].end(); j++) {
            int v = j->first;
            if(color[v]==BLACK) continue;
            if(d[v]>d[u]+j->second) {
                d[v] = d[u]+j->second;
                PQ.push(P(d[v], v));
                color[v] = GRAY;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(d[i]==INFTY) printf("%d -1\n", i);
        else printf("%d %d\n", i, d[i]);
    }
}

int main() {
    int k, c, u, v;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &u, &k);
        for(int j=0; j<k; j++) {
            scanf("%d %d", &v, &c);
            adj[u].push_back(P(v, c));
        }
    }
    dijkstra();
    return 0;
}