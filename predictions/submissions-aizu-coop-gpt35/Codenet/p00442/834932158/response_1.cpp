#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>

const int inf = 1e9 + 7;
const int INF = 1e18 + 7;

class t_sort {
public:
    int n;
    std::vector<int> ans, deg;
    std::vector<std::vector<int>> G;

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
        std::stack<int> st;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0)
                st.push(i);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            ans.push_back(v);
            for (int i = 0; i < G[v].size(); i++) {
                if (--deg[G[v][i]] == 0)
                    st.push(G[v][i]);
            }
        }
    }
};

int main() {
    int n, m;
    std::scanf("%lld%lld", &n, &m);
    t_sort t;
    t.init(n);
    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::scanf("%lld%lld", &x, &y);
        x--;
        y--;
        t.add_edge(x, y);
        mp[std::make_pair(x, y)] = 1;
    }
    t.tsort();
    std::vector<int> ans = t.ans;
    for (int i = 0; i < n; i++)
        std::printf("%lld\n", ans[i] + 1);
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (mp[std::make_pair(ans[i], ans[i + 1])] == 0)
            res = 0;
    }
    std::printf("%lld\n", res == 1 ? 0 : 1);
    return 0;
}