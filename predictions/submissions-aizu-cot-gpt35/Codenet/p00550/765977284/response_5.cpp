#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline void reader(int* x) {
    int k = getchar_unlocked();
    *x = k - '0';
    while (1) {
        k = getchar_unlocked();
        if (k < '0' || k > '9')
            break;
        *x = ((*x) << 1) + ((*x) << 3) + k - '0';
    }
}

vector<int> E[100000];
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[200000], ok[100000];

void bfs(int u, int t) {
    queue<int> que;
    que.push(u);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int v : E[p]) {
            if (t) {
                if (d[v] > d[p] && !ok[v]) {
                    ok[v] = 1;
                    cnt++;
                    que.push(v);
                }
            } else if (!~d[v]) {
                d[v] = d[p] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    int n, m, q;
    reader(&n);
    reader(&m);
    reader(&q);
  
    E.reserve(n);
  
    for (size_t i = 0; i < m; i++) {
        reader(&u[i]);
        reader(&v[i]);
        u[i]--;
        v[i]--;
        E[u[i]].emplace_back(v[i]);
        E[v[i]].emplace_back(u[i]);
    }
  
    memset(d, -1, sizeof(d));
    d[0] = 0;
    bfs(0, 0);
  
    for (size_t i = 0; i < m; i++) {
        if (d[u[i]] > d[v[i]])
            swap(u[i], v[i]);
    }
  
    for (size_t i = 0; i < n; i++)
        E[i].clear();
  
    for (size_t i = 0; i < q; i++) {
        reader(&r[i]);
        r[i]--;
        b[r[i]] = true;
    }
  
    ok[0] = true;
  
    for (size_t i = 0; i < m; i++) {
        if (!b[i]) {
            if (d[v[i]] - d[u[i]] == 1) {
                E[u[i]].emplace_back(v[i]);
            }
        }
    }
  
    bfs(0, 1);
  
    for (int i = q - 1; i >= 0; i--) {
        ans[i] = n - cnt;
        if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
            E[u[r[i]]].emplace_back(v[r[i]]);
            if (ok[u[r[i]]]) {
                cnt++;
                ok[v[r[i]]] = true;
                bfs(v[r[i]], 1);
            }
        }
    }
  
    for (size_t i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
}