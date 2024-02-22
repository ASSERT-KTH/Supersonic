#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<string, float> dp;

int K, R, L;
float P, E, T;

string make_key(int d, float l, float r) {
    return to_string(d) + "_" + to_string(l) + "_" + to_string(r);
}

float dfs(int d, float l, float r) {
    string key = make_key(d, l, r);
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

    float mid = (l + r) / 2;
    if (!d)
        return dp[key] = (T - E < mid && mid < T + E) ? 1 : 0;
    if (r < T - E || T + E < l)
        return dp[key] = 0;
    if (mid >= T)
        return dp[key] = (1.0f - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
    return dp[key] = (1.0f - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
    cin >> K >> L >> R >> P >> E >> T;
    printf("%.9f\n", dfs(K, L, R));
    return 0;
}