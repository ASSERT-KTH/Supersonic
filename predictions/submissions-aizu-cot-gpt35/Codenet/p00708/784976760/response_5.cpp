#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int root(vector<int>& parent, int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = root(parent, parent[a]);
}

bool unite(vector<int>& parent, int a, int b) {
    int x = root(parent, a);
    int y = root(parent, b);
    if (x == y)
        return false;
    parent[x] = y;
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        vector<vector<double>> v(n, vector<double>(4));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%lf", &v[i][j]);
            }
        }
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double x = 0;
                for (int k = 0; k < 3; k++) {
                    x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
                }
                x = sqrt(x) - v[i][3] - v[j][3];
                if (x <= 0) {
                    unite(parent, i, j);
                } else {
                    pq.push({x, i * n + j});
                }
            }
        }
        double x = 0;
        while (!pq.empty()) {
            double d = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            int a = idx / n;
            int b = idx % n;
            if (unite(parent, a, b)) {
                x += d;
            }
        }
        printf("%.3f\n", x);
    }
    return 0;
}