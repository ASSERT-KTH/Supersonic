#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void reader(int& x) {
    cin >> x;
}

vector<vector<int>> E;
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[200000], ok[100000];
queue<int> que;

void bfs(int u, int t) {
    que.push(u);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int v : E[p]) {
            if (t) {
                if (d[v] > d[p] && !ok[v]) {
                    ok[v] = true;
                    cnt++;
                    que.push(v);
                }
            } else if (d[v] == -1) {
                d[v] = d[p] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    int n, m, q;
    reader(n);
    reader(m);
    reader(q);
    E.resize(n);
    for (int i = 0; i < m; i++) {
        reader(u[i]);
        reader(v[i]);
        u[i]--;
        v[i]--;
        E[u[i]].push_back(v[i]);
        E[v[i]].push_back(u[i]);
    }
    fill(d, d + n, -1);
    d[0] = 0;
    bfs(0, 0);
    for (int i = 0; i < m; i++) {
        if (d[u[i]] > d[v[i]]) {
            int temp = u[i];
            u[i] = v[i];
            v[i] = temp;
        }
    }
    E.clear();
    E.resize(n);
    for (int i = 0; i < q; i++) {
        reader(r[i]);
        r[i]--;
        b[r[i]] = true;
    }
    ok[0] = true;
    for (int i = 0; i < m; i++) {
        if (!b[i]) {
            if (d[v[i]] - d[u[i]] == 1) {
                E[u[i]].push_back(v[i]);
            }
        }
    }
    bfs(0, 1);
    for (int i = q - 1; i >= 0; i--) {
        ans[i] = n - cnt;
        if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
            E[u[r[i]]].push_back(v[r[i]]);
            if (ok[u[r[i]]]) {
                cnt++;
                ok[v[r[i]]] = true;
                bfs(v[r[i]], 1);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}