#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

void search_loop(int i, vector<vector<int>>& G, vector<int>& color, vector<int>& d, vector<int>& f, int& t) {
    stack<int> s;
    s.push(i);
    while (!s.empty()) {
        i = s.top();
        if (color[i] == WHITE) {
            d[i] = ++t;
            color[i] = GRAY;
            for (int next : G[i]) {
                if (color[next] == WHITE) {
                    s.push(next);
                }
            }
        } else {
            s.pop();
            if (color[i] != BLACK) {
                f[i] = ++t;
                color[i] = BLACK;
            }
        }
    }
}

void dfs(int n, vector<vector<int>>& G) {
    vector<int> color(n+1, WHITE);
    vector<int> d(n+1), f(n+1);
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE)
            search_loop(i, G, color, d, f, t);
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    int n, i, e, k;
    cin >> n;
    vector<vector<int>> G(n+1);
    for (i = 1; i <= n; i++) {
        cin >> i >> e;
        G[i].resize(e);
        for (int j = 0; j < e; j++) {
            cin >> k;
            G[i][j] = k;
        }
    }
    dfs(n, G);
    return 0;
}