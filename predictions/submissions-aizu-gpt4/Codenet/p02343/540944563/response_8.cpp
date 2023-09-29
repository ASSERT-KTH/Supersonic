#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isSame(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> parent, rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);

    for (int i = 0; i < Q; i++) {
        int command, x, y;
        cin >> command >> x >> y;
        if (command == 0) {
            uf.unite(x, y);
        } else {
            cout << (uf.isSame(x, y) ? 1 : 0) << "\n";
        }
    }

    return 0;
}