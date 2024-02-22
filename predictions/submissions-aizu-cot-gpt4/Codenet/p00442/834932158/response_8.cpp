#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

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
            if (deg[i] == 0) 
                st.push(i);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            ans.push_back(v);
            for (size_t i = 0; i < G[v].size(); i++)
                if (--deg[G[v][i]] == 0)
                    st.push(G[v][i]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    t_sort t;
    t.init(n);
  
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        t.add_edge(x, y);
    }
  
    t.tsort();
    vector<int> ans = t.ans;
  
    for(int i=0; i<n; i++)
        cout << ans[i] + 1 << "\n";
  
    int res = 1;
    for(int i=0; i<n-1; i++) {
        if (find(t.G[ans[i]].begin(), t.G[ans[i]].end(), ans[i+1]) == t.G[ans[i]].end())
            res = 0;
    }
  
    cout << (res == 1 ? 0 : 1) << "\n";
    return 0;
}