#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <functional>

struct pair_hash {
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class t_sort {
public:
    int n;
    std::vector<int> deg, ans;
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
        
        ans.reserve(n);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            ans.push_back(v);
            for (int i = 0; i < G[v].size(); i++) 
                if (--deg[G[v][i]] == 0) 
                    st.push(G[v][i]);
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    t_sort t;
    t.init(n);

    std::unordered_map<std::pair<int, int>, int, pair_hash> mp;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        t.add_edge(x, y);
        mp[std::make_pair(x, y)] = 1;
    }
    t.tsort();

    for (int i = 0; i < n; i++) 
        std::cout << t.ans[i] + 1 << "\n";
    
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (mp[std::make_pair(t.ans[i], t.ans[i + 1])] == 0)
            res = 0;
    }
    std::cout << (res == 1 ? 0 : 1) << "\n";

    return 0;
}