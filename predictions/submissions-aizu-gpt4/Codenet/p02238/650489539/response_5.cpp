#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum color { WHITE, GRAY, BLACK };

vector<vector<int>> G;
vector<color> Color;
int n, t;
vector<int> d, f;

void search_loop(int i) {
    d[i] = ++t;
    Color[i] = GRAY;
    for (int next = 0; next < n; next++) {
        if (G[i][next] && Color[next] == WHITE) {
            search_loop(next);
        }
    }
    f[i] = ++t;
    Color[i] = BLACK;
}

void dfs() {
    fill(Color.begin(), Color.end(), WHITE);
    t = 0;
    for (int i = 0; i < n; i++) {
        if (Color[i] == WHITE)
            search_loop(i);
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    cin >> n;
    G.resize(n, vector<int>(n, 0));
    Color.resize(n);
    d.resize(n);
    f.resize(n);
    for (int i = 0; i < n; i++) {
        int e, k;
        cin >> e >> k;
        while (k--) {
            int j;
            cin >> j;
            G[e - 1][j - 1] = 1;
        }
    }
    dfs();
    return 0;
}