#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

#define MOD 1000000007

int N, M;
vector<int> g[1010], r[1010];
vector<bool> used(1010), inCycle(1010);
vector<int> cycle;
vector<long long> dp(1010, -1);

void dfs(int cur, set<int>& cycleSet) {
    if (used[cur]) {
        for (int i : cycle) {
            cycleSet.insert(i);
        }
        return;
    }
    used[cur] = true;
    cycle.push_back(cur);
    if (g[cur].empty()) {
        cycleSet.insert(cur);
        return;
    }
    for (int i : g[cur]) {
        dfs(i, cycleSet);
    }
}

long long solve(int v) {
    long long& res = dp[v];
    if (res != -1)
        return res;
    used[v] = true;
    res = 1;
    for (int i : r[v]) {
        res = (res * solve(i)) % MOD;
    }
    res = (res + 1) % MOD;
    return res;
}

long long f(int start) {
    set<int> cycleSet;
    cycle.clear();
    dfs(start, cycleSet);
    long long res = 1;
    for (int i : cycle) {
        inCycle[i] = true;
    }
    for (int i : cycle) {
        for (int j : r[i]) {
            if (inCycle[j])
                continue;
            res = (res * solve(j)) % MOD;
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
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans = (ans * f(i)) % MOD;
        }
    }
    cout << ans << endl;
}