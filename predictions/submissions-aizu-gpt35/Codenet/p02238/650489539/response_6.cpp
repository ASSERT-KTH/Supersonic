#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
vector<int> color, d, f;
int t;

void search_loop(int i) {
    d[i] = ++t;
    color[i] = 1;
    for (auto next : G[i]) {
        if (color[next] == 0) {
            search_loop(next);
        }
    }
    f[i] = ++t;
    color[i] = 2;
}

void dfs() {
    color.resize(G.size());
    d.resize(G.size());
    f.resize(G.size());
    t = 0;
    for (int i = 1; i < G.size(); i++) {
        if (color[i] == 0) {
            search_loop(i);
        }
    }
    for (int i = 1; i < G.size(); i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    int n, i, j, k, e;
    cin >> n;
    G.resize(n + 1);
    while (cin >> i, i != 0) {
        G[i].resize(0);
        while (cin >> j, j != 0) {
            G[i].push_back(j);
        }
    }
    dfs();
    return 0;
}