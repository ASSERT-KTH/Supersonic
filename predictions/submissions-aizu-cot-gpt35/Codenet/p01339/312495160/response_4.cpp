#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

int N, M;
vector<vector<int>> g, r;
unordered_map<int, int> used;
vector<int> cycle;
unordered_map<int, int> inCycle;
vector<ll> dp;

void dfs(int cur, vector<int>& List) {
    if (used[cur]) {
        int from = 0;
        while (List[from] != cur)
            from++;
        for (int i = from; i < List.size(); i++) {
            cycle.push_back(List[i]);
        }
        return;
    }
    used[cur] = 1;
    List.push_back(cur);
    if (g[cur].empty()) {
        cycle.push_back(cur);
        return;
    }
    for (int i = 0; i < g[cur].size(); i++) {
        dfs(g[cur][i], List);
    }
}

void solve(int v, unordered_map<int, int>& used, vector<ll>& dp) {
    ll& res = dp[v];
    if (res != -1)
        return;
    used[v] = 1;
    res = 1;
    for (int i = 0; i < r[v].size(); i++) {
        solve(r[v][i], used, dp);
        res = res * dp[r[v][i]] % MOD;
    }
    res = (res + 1) % MOD;
}

ll f(int start) {
    vector<int> List;
    cycle.clear();
    dfs(start, List);
    ll res = 1;
    for (int i = 0; i < cycle.size(); i++) {
        inCycle[cycle[i]] = 1;
    }
    for (int i = 0; i < cycle.size(); i++) {
        for (int j = 0; j < r[cycle[i]].size(); j++) {
            if (inCycle[r[cycle[i]][j]])
                continue;
            solve(r[cycle[i]][j], used, dp);
            res = res * dp[r[cycle[i]][j]] % MOD;
        }
    }
    res = (res + 1) % MOD;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    g.resize(N);
    r.resize(N);
    dp.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        g[s].emplace_back(d);
        r[d].emplace_back(s);
    }
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans = ans * f(i) % MOD;
        }
    }
    cout << ans << endl;
}