#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;
#define int long long
#define repi(i, m, n) for (int i = m; i < n; i++)
#define rep(i, n) repi(i, 0, n)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int, int> P;
typedef vector<int> vi;
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
        G[from].pb(to);
        deg[to]++;
    }
    void tsort() {
        stack<int> st;
        rep(i, n) if (deg[i] == 0) st.push(i);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            ans.pb(v);
            rep(i, G[v].size()) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    t_sort t;
    t.init(n);
    set<P> edgeSet;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        t.add_edge(x, y);
        edgeSet.insert(P(x, y));
    }
    t.tsort();
    vector<int> ans = t.ans;
    rep(i, n) cout << ans[i] + 1 << "\n";
    int res = 1;
    rep(i, n - 1) {
        if (edgeSet.count(P(ans[i], ans[i + 1])) == 0)
            res = 0;
    }
    cout << (res == 1 ? 0 : 1) << "\n";
    return 0;
}