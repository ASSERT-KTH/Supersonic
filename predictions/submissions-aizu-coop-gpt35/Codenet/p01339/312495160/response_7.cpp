#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MOD = 1000000007;
constexpr int MAX_N = 1010;

int N, M;
vector<int> g[MAX_N], r[MAX_N];
bool visited[MAX_N];
int cycle[MAX_N], inCycle[MAX_N];
int dp[MAX_N];

void dfs(int cur, int start, vector<int>& stack) {
    if (visited[cur]) {
        int from = 0;
        while (stack[from] != cur)
            from++;
        for (int i = from; i < stack.size(); i++) {
            cycle[i - from] = stack[i];
        }
        return;
    }
    visited[cur] = true;
    stack.push_back(cur);
    if (g[cur].empty()) {
        cycle[0] = cur;
        return;
    }
    for (int i : g[cur]) {
        dfs(i, start, stack);
    }
    stack.pop_back();
}

int solve(int v) {
    int& res = dp[v];
    if (res != -1)
        return res;
    res = 1;
    for (int i : r[v]) {
        res = (res * solve(i)) % MOD;
    }
    res = (res + 1) % MOD;
    return res;
}

int f(int start) {
    vector<int> stack;
    dfs(start, start, stack);
    int res = 1;
    for (int i : cycle) {
        inCycle[i] = 1;
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
    memset(dp, -1, sizeof(dp));
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ans = (ans * f(i)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}