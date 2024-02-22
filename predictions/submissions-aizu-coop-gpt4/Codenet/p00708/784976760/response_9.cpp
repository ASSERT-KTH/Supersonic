#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 9999

struct Node {
    int x, y;
    double dist;
};

int parent[MAXN];

int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }

bool unite(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y)
        return false;
    parent[x] = y;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<vector<double>> v(n, vector<double>(4));
        for (auto &i : v)
            cin >> i[0] >> i[1] >> i[2] >> i[3];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<Node> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = 0;
                for (int k = 0; k < 3; k++)
                    dist += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
                dist -= (v[i][3] + v[j][3]) * (v[i][3] + v[j][3]);
                if (dist <= 0)
                    unite(i, j);
                else
                    edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end(), [](const Node &a, const Node &b) {
            return a.dist < b.dist;
        });

        double total_dist = 0;
        for (const auto &edge : edges)
            if (unite(edge.x, edge.y))
                total_dist += sqrt(edge.dist);

        cout.precision(3);
        cout << fixed << total_dist << '\n';
    }
}