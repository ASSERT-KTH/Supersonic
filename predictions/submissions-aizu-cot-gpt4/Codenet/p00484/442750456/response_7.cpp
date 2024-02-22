#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

ll d[15][2005], dp[2005][2005];

int main() {
    int n, K;
    cin >> n >> K;
    set<int> id_set;
    vector<int> v[2005];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        id_set.insert(b - 1);
        v[b - 1].push_back(a);
    }

    vector<int> id(id_set.begin(), id_set.end());

    for (int i = 0; i < id.size(); i++) {
        int j = id[i];
        sort(v[j].begin(), v[j].end(), greater<int>());
    }

    memset(d, 0, sizeof(d));

    for (int i = 0; i < id.size(); i++) {
        int j = id[i];
        for (int k = 1; k < v[j].size() + 1; k++) {
            d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
        }
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < id.size(); i++) {
        for (int j = 0; j < K + 1; j++) {
            ll res = dp[i][j];
            for (int k = 0; k < v[id[i]].size() + 1; k++) {
                if (j >= k) {
                    res = max(res, dp[i][j - k] + d[id[i]][k]);
                }
            }
            dp[i + 1][j] = res;
        }
    }

    cout << dp[id.size()][K] << endl;
    return 0;
}