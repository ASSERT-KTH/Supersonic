#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

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
        for (int i = 0; i < n; i++) if (deg[i] == 0) st.push(i);
        while (!st.empty()) {
            int v = st.top(); st.pop();
            ans.push_back(v);
            for (int i = 0; i < G[v].size(); i++) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
        }
    }
};

map<P, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    t_sort t;
    t.init(n);
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        t.add_edge(x, y);
        mp[P(x, y)] = 1;
    }
    t.tsort();
    vector<int> ans = t.ans;
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << "\n";

    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (mp[P(ans[i], ans[i + 1])] == 0)
            res = 0;
    }
    cout << (res == 1 ? 0 : 1) << "\n";
    return 0;
}