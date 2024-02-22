#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 200000;
const int MAX_Q = 200000;

vector<int> E[MAX_N];
int u[MAX_M], v[MAX_M], r[MAX_Q], ans[MAX_Q], d[MAX_N], cnt = 1;
bitset<MAX_N> b, ok;

void bfs(int start, int t) {
    queue<int> que;
    que.push(start);
    
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        
        for (int i = 0; i < E[p].size(); i++) {
            int v = E[p][i];
            
            if (t) {
                if (d[v] > d[p] && !ok[v]) {
                    ok[v] = 1;
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
    cin >> n >> m >> q;
    
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        E[u[i]].push_back(v[i]);
        E[v[i]].push_back(u[i]);
    }
    
    memset(d, -1, sizeof(d));
    d[0] = 0;
    bfs(0, 0);
    
    for (int i = 0; i < m; i++) {
        if (d[u[i]] > d[v[i]]) {
            swap(u[i], v[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        E[i].clear();
    }
    
    for (int i = 0; i < q; i++) {
        cin >> r[i];
        r[i]--;
        b[r[i]] = true;
    }
    
    ok[0] = true;
    
    for (int i = 0; i < m; i++) {
        if (!b[i] && d[v[i]] - d[u[i]] == 1) {
            E[u[i]].push_back(v[i]);
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
    
    return 0;
}