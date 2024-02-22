#include <algorithm>
#include <cstdio>
#include <vector>
#define M 9999
int parent[M], a[M], b[M];
std::pair<double, int> node[M];

int root(int a) {
    if (parent[a] != a)
        parent[a] = root(parent[a]);
    return parent[a];
}

bool unite(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y)
        return false;
    parent[x] = y;
    return true;
}

int main() {
    int i, j, k, m, n;
    double x, y, z, r;
    while(scanf("%d", &n) != EOF && n) {
        std::vector<std::vector<double>> v(n, std::vector<double>(4));
        for (i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
            v[i] = {x, y, z, r};
        }
        for (i = 0; i < n; i++)
            parent[i] = i;
        m = 0;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                double dist_square = 0;
                for (k = 0; k < 3; k++)
                    dist_square += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
                double radii_sum = (v[i][3] + v[j][3]) * (v[i][3] + v[j][3]);
                if (dist_square <= radii_sum)
                    unite(i, j);
                else {
                    a[m] = i, b[m] = j;
                    node[m].first = dist_square - radii_sum;
                    node[m++].second = m;
                }
            }
        }
        sort(node, node + m);
        for (x = 0, i = 0; i < m; i++) {
            if (unite(a[node[i].second], b[node[i].second]))
                x += node[i].first;
        }
        printf("%.3f\n", sqrt(x));
    }
    return 0;
}