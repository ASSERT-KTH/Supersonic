#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 6001;
const int INF = 1e9;

vector<int> pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];

int dijk(int s, int g) {
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        if (v == g) {
            return d[v];
        }
        for (int i = 0; i < pass[v].size(); i++) {
            int u = pass[v][i];
            int dist = (i == 0) ? c[v] : r[v];
            if (d[u] > d[v] + dist) {
                d[u] = d[v] + dist;
                q.push({d[u], u});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> r[i];
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    cout << dijk(0, n - 1) << endl;
    return 0;
}