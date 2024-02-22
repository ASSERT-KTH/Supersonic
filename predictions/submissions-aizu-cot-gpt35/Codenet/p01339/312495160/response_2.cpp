#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1010;

int N, M;
vector<int> g[MAX_N], r[MAX_N];
int used[MAX_N];
int List[MAX_N], l;
int cycle[MAX_N], c;
int inCycle[MAX_N];
int dp[MAX_N];

void dfs(int cur) {
    if (used[cur]) {
        int from = 0;
        while (List[from] != cur)
            ++from;
        for (int i = from; i < l; ++i) {
            cycle[c++] = List[i];
        }
        return;
    }
    used[cur] = 1;
    List[l++] = cur;
    if (g[cur].empty()) {
        cycle[c++] = cur;
        return;
    }
    for (int i : g[cur]) {
        dfs(i);
    }
}

int solve(int v) {
    int& res = dp[v];
    if (res != -1)
        return res;
    used[v] = 1;
    res = 1;
    for (int i : r[v]) {
        res = (res * solve(i)) % MOD;
    }
    res = (res + 1) % MOD;
    return res;
}

int f(int start) {
    l = 0;
    c = 0;
    dfs(start);
    int res = 1;
    for (int i = 0; i < c; ++i) {
        inCycle[cycle[i]] = 1;
    }
    for (int i = 0; i < c; ++i) {
        for (int j : r[cycle[i]]) {
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
    for (int i = 0; i < M; ++i) {
        int s, d;
        cin >> s >> d;
        --s;
        --d;
        g[s].push_back(d);
        r[d].push_back(s);
    }
    fill(dp, dp + N, -1);
    int ans = 1;
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            ans = (ans * f(i)) % MOD;
        }
    }
    cout << ans << endl;
}