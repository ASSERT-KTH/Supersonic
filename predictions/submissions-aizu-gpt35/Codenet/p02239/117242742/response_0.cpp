#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 105;
vector<int> G[MAXN];
int n, d[MAXN];

void bfs(int s) {
    fill(d, d + n, -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            G[u - 1].push_back(v - 1);
        }
    }
    bfs(0);
    for (int i = 0; i < n; i++)
        cout << i + 1 << ' ' << d[i] << endl;
    return 0;
}