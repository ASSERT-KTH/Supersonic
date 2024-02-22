#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MOD = 1000000007;

int N, M;
vector<int> g[1010], r[1010];
int used[1010];
stack<int> List;
unordered_set<int> inCycle;
unordered_map<int, long long> dp;

void dfs(int& cur) {
    if (used[cur]) {
        while (List.top() != cur) {
            inCycle.insert(List.top());
            List.pop();
        }
        inCycle.insert(cur);
        return;
    }
    used[cur] = 1;
    List.push(cur);
    if (g[cur].empty()) {
        inCycle.insert(cur);
        return;
    }
    for (int i = 0; i < g[cur].size(); i++) {
        dfs(g[cur][i]);
    }
}

long long solve(int& v) {
    long long& res = dp[v];
    if (res != 0)
        return res;
    used[v] = 1;
    res = 1;
    for (int i = 0; i < r[v].size(); i++) {
        res = (res * solve(r[v][i])) % MOD;
    }
    res = (res + 1) % MOD;
    return res;
}

long long f(int& start) {
    dfs(start);
    long long res = 1;
    for (const auto& node : inCycle) {
        for (const auto& neighbor : r[node]) {
            if (inCycle.count(neighbor) == 0) {
                res = (res * solve(neighbor)) % MOD;
            }
        }
    }
    res = (res + 1) % MOD;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        g[s].push_back(d);
        r[d].push_back(s);
    }
    memset(used, 0, sizeof(used));
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans = (ans * f(i)) % MOD;
        }
    }
    cout << ans << endl;
}