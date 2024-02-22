#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9;
const int MAXN = 6000;

vector<int> pass[MAXN];
int c[MAXN];
int r[MAXN];
int d[MAXN];
bool used[MAXN];
int n, k;

int dijk(int s, int g) {
    fill(d, d + MAXN, INF);
    fill(used, used + MAXN, false);
    d[s] = 0;
    while (1) {
        int v = -1;
        for (int u = 0; u < n; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        used[v] = true;
        for (int i = 0; i < pass[v].size(); i++) {
            int u = pass[v][i];
            d[u] = min(d[u], d[v] + c[v]);
        }
    }
    return d[g];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> c[i] >> r[i];
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