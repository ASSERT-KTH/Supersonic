#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;
using P = pair<int, int>;

const int INF = 1e18 + 7;

class t_sort {
public:
    int n;
    vector<int> ans, deg;
    vector<vector<int>> G;

    void init(int N) {
        n = N;
        deg.resize(n);
        G.resize(n);
    }

    void add_edge(int from, int to) {
        G[from].push_back(to);
        deg[to]++;
    }

    void tsort() {
        stack<int> st;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) st.push(i);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            ans.push_back(v);
            for (int i = 0; i < G[v].size(); i++)
                if (--deg[G[v][i]] == 0) st.push(G[v][i]);
        }
    }
};

map<P, int> mp;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    t_sort t;
    t.init(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        t.add_edge(x, y);
        mp[P(x, y)] = 1;
    }
    t.tsort();
    vector<int> ans = t.ans;
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i] + 1);
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (mp[P(ans[i], ans[i + 1])] == 0)
            res = 0;
    }
    printf("%d\n", res == 1 ? 0 : 1);
    return 0;
}