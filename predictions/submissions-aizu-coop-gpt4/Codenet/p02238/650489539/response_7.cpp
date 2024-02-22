#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> G(101);
vector<int> color(101);
vector<int> d(101), f(101);
int n, t;

void search_loop(int i) {
    stack<int> st;
    st.push(i);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (color[node] == WHITE) {
            color[node] = GRAY;
            d[node] = ++t;

            for (int next : G[node]) {
                if (color[next] == WHITE) {
                    st.push(next);
                }
            }

            color[node] = BLACK;
            f[node] = ++t;
        }
    }
}

void dfs() {
    fill(color.begin(), color.begin() + n + 1, WHITE);
    t = 0;

    for (int i = 1; i <= n; i++)
        if (color[i] == WHITE)
            search_loop(i);

    for (int i = 1; i <= n; i++)
        cout << i << " " << d[i] << " " << f[i] << endl;
}

int main() {
    cin >> n;

    int i, e, k;
    for (int _ = 0; _ < n; _++) {
        cin >> i >> e;
        while (e--) {
            cin >> k;
            G[i].push_back(k);
        }
    }

    dfs();

    return 0;
}