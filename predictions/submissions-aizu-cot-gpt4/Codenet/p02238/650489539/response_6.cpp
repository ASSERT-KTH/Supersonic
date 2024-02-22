#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<int> G[101];
int color[101];
int n;
int d[101], f[101], t;

void search_loop(int i) {
    d[i] = ++t;
    color[i] = GRAY;
    for (int next : G[i]) {
        if (color[next] == WHITE) {
            search_loop(next);
        }
    }
    f[i] = ++t;
    color[i] = BLACK;
}

void dfs() {
    t = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE)
            search_loop(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    cin >> n;
    int i, j, k, e;
    do {
        cin >> i >> e;
        for (j = 1; j <= e; j++) {
            cin >> k;
            G[i].push_back(k);
        }
    } while (i < n);

    dfs();

    return 0;
}