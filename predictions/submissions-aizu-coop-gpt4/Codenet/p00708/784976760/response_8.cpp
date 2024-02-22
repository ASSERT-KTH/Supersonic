#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define M 9999

struct Node {
    double x, y, z, r;
};

struct Edge {
    double w;
    int a, b;
};

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n): parent(n), rank(n, 0) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            if(rank[rootX] == rank[rootY]) ++rank[rootY];
        }
    }
};

auto comp = [](Edge a, Edge b) { return a.w > b.w; };
priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);

int main() {
    int n;
    while(cin >> n && n) {
        vector<Node> nodes(n);
        for(int i = 0; i < n; ++i)
            cin >> nodes[i].x >> nodes[i].y >> nodes[i].z >> nodes[i].r;
        
        UnionFind uf(n);
        while(!pq.empty()) pq.pop();

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                double dist = sqrt(pow(nodes[i].x - nodes[j].x, 2) + 
                                   pow(nodes[i].y - nodes[j].y, 2) + 
                                   pow(nodes[i].z - nodes[j].z, 2)) - 
                                   nodes[i].r - nodes[j].r;
                if(dist <= 0) uf.unite(i, j);
                else pq.push({dist, i, j});
            }
        }
        double res = 0;
        while(!pq.empty()) {
            Edge e = pq.top(); pq.pop();
            if(uf.find(e.a) != uf.find(e.b)) {
                res += e.w;
                uf.unite(e.a, e.b);
            }
        }
        printf("%.3f\n", res);
    }
    return 0;
}