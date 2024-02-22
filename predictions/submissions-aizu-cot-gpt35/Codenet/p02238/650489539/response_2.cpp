#include <iostream>
#include <vector>
#include <stack>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

vector<vector<int>> G;
vector<Color> color;
vector<int> d, f;
int t;

void search_loop(int start) {
    stack<int> stk;
    stk.push(start);
    color[start] = GRAY;
    d[start] = ++t;

    while (!stk.empty()) {
        int i = stk.top();
        stk.pop();

        for (int next = 1; next <= G.size(); next++) {
            if (G[i][next] > 0 && color[next] == WHITE) {
                stk.push(next);
                color[next] = GRAY;
                d[next] = ++t;
            }
        }

        f[i] = ++t;
        color[i] = BLACK;
    }
}

void dfs() {
    for (int i = 1; i <= G.size(); i++)
        color[i] = WHITE;
    t = 0;

    for (int i = 1; i <= G.size(); i++) {
        if (color[i] == WHITE)
            search_loop(i);
    }

    for (int i = 1; i <= G.size(); i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    G.resize(n + 1, vector<int>(n + 1, 0));
    color.resize(n + 1, WHITE);
    d.resize(n + 1, 0);
    f.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;

        for (int j = 1; j <= e; j++) {
            int k;
            cin >> k;
            G[i][k] = 1;
        }
    }

    dfs();

    return 0;
}