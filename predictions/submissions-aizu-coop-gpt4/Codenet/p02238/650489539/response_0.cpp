#include <iostream>
#include <vector>

using namespace std;

enum Color {
    WHITE, GRAY, BLACK
};

void dfs(int n, vector<vector<int>>& G) {
    vector<int> color(n + 1, WHITE);
    vector<int> d(n + 1, 0);
    vector<int> f(n + 1, 0);
    int t = 0;

    function<void(int)> search_loop = [&](int i) {
        color[i] = GRAY;
        d[i] = ++t;
        for (int next : G[i]) {
            if (color[next] == WHITE) {
                search_loop(next);
            }
        }
        f[i] = ++t;
        color[i] = BLACK;
    };

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) {
            search_loop(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> G(n + 1);

    for (int i = 1; i <= n; i++) {
        int e;
        cin >> i >> e;
        G[i].resize(e);
        for (int j = 0; j < e; j++) {
            cin >> G[i][j];
        }
    }

    dfs(n, G);

    return 0;
}