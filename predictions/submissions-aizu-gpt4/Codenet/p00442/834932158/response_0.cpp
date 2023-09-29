#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

class TopologicalSort {
public:
    ll n;
    vector<ll> result, inDegree;
    vector<vector<ll>> graph;

    TopologicalSort(ll N) {
        n = N;
        inDegree.resize(n, 0);
        graph.resize(n);
    }

    void addEdge(ll from, ll to) {
        graph[from].push_back(to);
        inDegree[to]++;
    }

    void sort() {
        stack<ll> st;
        for (ll i = 0; i < n; i++) 
            if (inDegree[i] == 0) 
                st.push(i);
        while (!st.empty()) {
            ll v = st.top();
            st.pop();
            result.push_back(v);
            for (auto &u : graph[v]) 
                if (--inDegree[u] == 0) 
                    st.push(u);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    TopologicalSort ts(n);
    map<P, ll> mp;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        ts.addEdge(x, y);
        mp[P(x, y)] = 1;
    }
    ts.sort();
    vector<ll> ans = ts.result;

    for (auto &i : ans)
        cout << i + 1 << "\n";

    ll res = 1;
    for (ll i = 0; i < n - 1; i++) {
        if (mp[P(ans[i], ans[i + 1])] == 0)
            res = 0;
    }
    cout << (res == 1 ? 0 : 1) << "\n";
    return 0;
}