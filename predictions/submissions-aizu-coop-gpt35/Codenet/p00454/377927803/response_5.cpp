#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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

    void unionSets(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    int n;
    while (cin >> w >> h, w) {
        cin >> n;

        vector<int> x1(n), x2(n), y1(n), y2(n);
        for (int i = 0; i < n; i++) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }

        vector<int> xs, ys;
        for (int i = 0; i < n; i++) {
            for (int d = -1; d <= 1; ++d) {
                int tx1 = x1[i] + d, tx2 = x2[i] + d;
                if (0 <= tx1 && tx1 <= w) {
                    xs.push_back(tx1);
                }
                if (0 <= tx2 && tx2 <= w) {
                    xs.push_back(tx2);
                }
            }
            for (int d = -1; d <= 1; ++d) {
                int ty1 = y1[i] + d, ty2 = y2[i] + d;
                if (0 <= ty1 && ty1 <= h) {
                    ys.push_back(ty1);
                }
                if (0 <= ty2 && ty2 <= h) {
                    ys.push_back(ty2);
                }
            }
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int w_compressed = xs.size();
        int h_compressed = ys.size();

        DisjointSet ds(w_compressed * h_compressed);

        for (int i = 0; i < n; i++) {
            for (int y = y1[i]; y < y2[i]; y++) {
                for (int x = x1[i]; x < x2[i]; x++) {
                    int compressed_y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
                    int compressed_x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
                    int compressed_idx = compressed_y * w_compressed + compressed_x;
                    ds.unionSets(compressed_idx, compressed_idx);
                }
            }
        }

        int ans = 0;
        for (int y = 0; y < h_compressed - 1; y++) {
            for (int x = 0; x < w_compressed - 1; x++) {
                int compressed_idx = y * w_compressed + x;
                if (ds.find(compressed_idx) == compressed_idx) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}