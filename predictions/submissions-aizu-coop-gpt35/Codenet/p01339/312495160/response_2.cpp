#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

ll solve(int v, const vector<vector<int>>& g, vector<ll>& dp) {
    ll& res = dp[v];
    if (res != -1)
        return res;
    res = 1;
    for (int i = 0; i < g[v].size(); i++) {
        res = res * solve(g[v][i], g, dp) % MOD;
    }
    res = (res + 1) % MOD;
    return res;
}

ll countPaths(int start, const vector<vector<int>>& g) {
    int N = g.size();
    vector<ll> dp(N, -1);
    vector<bool> visited(N, false);
    vector<int> cycle;
    vector<bool> inCycle(N, false);
    vector<int> stack;

    stack.push_back(start);
    visited[start] = true;

    while (!stack.empty()) {
        int cur = stack.back();

        if (visited[cur]) {
            stack.pop_back();
            int from = 0;
            while (cycle[from] != cur)
                from++;
            for (int i = from; i < cycle.size(); i++) {
                inCycle[cycle[i]] = true;
            }
            continue;
        }

        visited[cur] = true;
        cycle.push_back(cur);

        if (g[cur].empty()) {
            inCycle[cur] = true;
            continue;
        }

        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i];
            if (!visited[next]) {
                stack.push_back(next);
            }
        }
    }

    ll res = 1;
    for (int i = 0; i < cycle.size(); i++) {
        int cur = cycle[i];
        for (int j = 0; j < g[cur].size(); j++) {
            int next = g[cur][j];
            if (!inCycle[next]) {
                res = res * solve(next, g, dp) % MOD;
            }
        }
    }

    res = (res + 1) % MOD;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        g[s].push_back(d);
    }

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (g[i].empty()) {
            ans = ans * (MOD + 1) % MOD;
        } else if (!visited[i]) {
            ans = ans * countPaths(i, g) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}