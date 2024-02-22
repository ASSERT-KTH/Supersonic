#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const ll MOD = 1000000007LL;

struct Graph {
    int N, M;
    vi g[1010], r[1010];
    int used[1010];
    vi List, cycle;
    set<int> inCycle;
    ll dp[1010];

    Graph(int N, int M) : N(N), M(M), List(0), cycle(0) {
        memset(dp, -1, sizeof(dp));
        memset(used, 0, sizeof(used));
    }

    void dfs(int cur) {
        if (used[cur]) {
            int from = 0;
            while (List[from] != cur)
                from++;
            for(int i = from; i < List.size(); i++) { cycle.push_back(List[i]); }
            return;
        }
        used[cur] = 1;
        List.push_back(cur);
        if (g[cur].size() == 0) {
            cycle.push_back(cur);
            return;
        }
        for(auto i : g[cur]) { dfs(i); }
    }

    ll solve(int v) {
        ll &res = dp[v];
        if (res != -1)
            return res;
        used[v] = 1;
        res = 1;
        for(auto i : r[v]) { res = res * solve(i) % MOD; }
        res = (res + 1) % MOD;
        return res;
    }

    ll f(int start) {
        List.clear();
        cycle.clear();
        dfs(start);
        ll res = 1;
        for(auto i : cycle) inCycle.insert(i);
        for(auto i : cycle) 
            for(auto j : r[i]) {
                if (inCycle.count(j))
                    continue;
                res = res * solve(j) % MOD;
            }
        res = (res + 1) % MOD;
        return res;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;

    Graph graph(N, M);

    for(int i = 0; i < M; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        graph.g[s].push_back(d);
        graph.r[d].push_back(s);
    }

    ll ans = 1;
    for(int i = 0; i < N; i++) 
        if (!graph.used[i]) { ans = ans * graph.f(i) % MOD; }

    cout << ans << endl;
}