#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
pair<double, int> node[M];

inline int root(int a) {
    while (a != parent[a]) a = parent[a] = parent[parent[a]];
    return a;
}

inline bool unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    int i, j, m, n;
    double x, y, z, r;
    while (scanf("%d", &n), n) {
        vector<vector<double>> v(n, vector<double>(4));
        for (i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
            parent[i] = i;
        }
        for (m = 0, i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j) {
                double dist = 0.0;
                for (int k = 0; k < 3; ++k) dist += pow(v[i][k] - v[j][k], 2);
                dist = sqrt(dist) - v[i][3] - v[j][3];
                if (dist <= 0) unite(i, j);
                else a[m] = i, b[m] = j, node[m] = {dist, m}, ++m;
            }
        sort(node, node + m);
        double total = 0.0;
        for (i = 0; i < m; ++i) if (unite(a[node[i].second], b[node[i].second])) total += node[i].first;
        printf("%.3f\n", total);
    }
    return 0;
}