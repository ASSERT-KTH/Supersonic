#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1010;

int N, M;
vector<int> g[MAX_N], r[MAX_N];
vector<int> used(MAX_N);
vector<int> List, cycle;
vector<int> inCycle;
vector<long long> dp;

void dfs(int cur) {
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
    for (int i : g[cur]) {
        dfs(i);
    }
}

long long solve(int& v) {
    long long& res = dp[v];
    if (res != -1)
        return res;
    used[v] = 1;
    res = 1;
    for (int i : r[v]) {
        res = res * solve(i) % MOD;
    }
    res = (res + 1) % MOD;
    return res;
}

long long f(int start) {
    List.clear();
    cycle.clear();
    dfs(start);
    long long res = 1;
    inCycle.assign(N, 0);
    for (int i : cycle) {
        inCycle[i] = 1;
    }
    for (int i : cycle) {
        for (int j : r[i]) {
            if (inCycle[j])
                continue;
            res = res * solve(j) % MOD;
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
        g[s].emplace_back(d);
        r[d].emplace_back(s);
    }
    dp.assign(N, -1);
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans = ans * f(i) % MOD;
        }
    }
    cout << ans << endl;
}