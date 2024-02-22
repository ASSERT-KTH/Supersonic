#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

const int M = 9999;

int parent[M];
std::vector<std::pair<double, int>> node;
std::vector<int> a, b;

int root(int a) {
    return parent[a] == a ? a : parent[a] = root(parent[a]);
}

int unite(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y)
        return 0;
    parent[x] = y;
    return 1;
}

int main() {
    int i, j, m, n;
    double x, y, z, r;
    for (; std::scanf("%d", &n), n;) {
        std::vector<std::vector<double>> v;
        v.reserve(n);
        for (i = 0; i < n; i++) {
            std::scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
            v.emplace_back(std::initializer_list<double>{x, y, z, r});
        }
        for (i = 0; i < n; i++)
            parent[i] = i;
        node.clear();
        a.clear();
        b.clear();
        for (m = i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                x = 0;
                for (int k = 0; k < 3; k++)
                    x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
                x = std::sqrt(x) - v[i][3] - v[j][3];
                if (x <= 0)
                    unite(i, j);
                else
                    node.emplace_back(x, m++);
            }
        }
        std::sort(node.begin(), node.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        double cost = 0;
        for (i = 0; i < m; i++) {
            if (unite(a[node[i].second], b[node[i].second]))
                cost += node[i].first;
        }
        std::printf("%.3f\n", cost);
    }
    return 0;
}