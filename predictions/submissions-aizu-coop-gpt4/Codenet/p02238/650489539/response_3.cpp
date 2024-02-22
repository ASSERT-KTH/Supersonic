#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G;
vector<int> color;
vector<int> d, f;
int n, t;

void dfs() {
    stack<int> S;
    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) {
            S.push(i);
            while (!S.empty()) {
                int u = S.top();
                S.pop();
                if (color[u] == WHITE) {
                    d[u] = ++t;
                    color[u] = GRAY;
                    S.push(u);
                    for (int v : G[u]) {
                        if (color[v] == WHITE) {
                            S.push(v);
                        }
                    }
                } else if (color[u] == GRAY) {
                    f[u] = ++t;
                    color[u] = BLACK;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    cin >> n;
    G.resize(n + 1);
    d.resize(n + 1);
    f.resize(n + 1);
    color.resize(n + 1, WHITE);
    int i, j, k, e;
    do {
        cin >> i >> e;
        for (j = 1; j <= e; j++) {
            cin >> k;
            G[i].push_back(k);
        }
    } while (i < n);
    t = 0;
    dfs();
    cin >> n;
    return 0;
}