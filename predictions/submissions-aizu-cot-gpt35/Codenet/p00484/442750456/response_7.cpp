#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> id, v[2005];
    id.reserve(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        id.push_back(b - 1);
        v[b - 1].push_back(a);
    }
    sort(id.begin(), id.end());
    id.erase(unique(id.begin(), id.end()), id.end());
    for (int i = 0; i < id.size(); i++) {
        int j = id[i];
        sort(v[j].begin(), v[j].end(), greater<int>());
    }
    vector<vector<ll>> d(id.size(), vector<ll>(2005));
    vector<P> p;
    for (int i = 0; i < id.size(); i++) {
        int j = id[i];
        for (int k = 1; k <= v[j].size(); k++) {
            d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
            p.emplace_back(k, d[j][k]);
        }
    }
    vector<vector<ll>> dp(id.size() + 1, vector<ll>(K + 1));
    for (int i = 0; i < id.size(); i++) {
        for (int j = 0; j <= K; j++) {
            ll res = dp[i][j];
            auto it = max_element(dp[i].begin(), dp[i].begin() + min(K, (int)v[id[i]].size()) + 1);
            if (it != dp[i].end()) {
                res = max(res, *it + d[id[i]][it - dp[i].begin()]);
            }
            dp[i + 1][j] = res;
        }
    }
    cout << dp[id.size()][K] << endl;
    return 0;
}