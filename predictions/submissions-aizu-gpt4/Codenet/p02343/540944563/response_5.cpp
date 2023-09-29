#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for(int i = 0; i < size; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for(int i = 0; i < Q; i++) {
        int command, x, y;
        cin >> command >> x >> y;
        if (command == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.is_same(x, y) << '\n';
        }
    }
    return 0;
}