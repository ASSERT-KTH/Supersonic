#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M];
pair<int, int> ab[M];
pair<double, int> node[M];

inline int root(int a) { 
    while(a != parent[a]) a = parent[a] = parent[parent[a]];
    return a;
}

inline bool unite(int a, int b) {
    int x = root(a), y = root(b);
    if (x != y) {
        parent[x] = y;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j, k, m, n;
    double x, y, z, r;
    for (; scanf("%d", &n), n;) {
        vector<vector<double>> v;
        v.reserve(n);
        for (i = 0; i < n; i++)
            parent[i] = i;
        for (i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &x, &y, &z, &r), v.push_back({x, y, z, r});
        for (m = i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                for (x = k = 0; k < 3; k++)
                    x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
                x = sqrt(x) - v[i][3] - v[j][3];
                if (x <= 0)
                    unite(i, j);
                else
                    ab[m] = {i, j}, node[m].first = x, node[m++].second = m;
            }
        sort(node, node + m);
        for (x = i = 0; i < m; i++)
            if (unite(ab[node[i].second].first, ab[node[i].second].second))
                x += node[i].first;
        printf("%.3f\n", x);
    }
}