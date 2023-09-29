#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[2005][2005];
ll sum[2005][2005];
int pre[2005][2005];
vector<int> v[2005];
vector<int> id;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        id.push_back(b - 1);
        v[b - 1].push_back(a);
    }

    sort(id.begin(), id.end());
    id.erase(unique(id.begin(), id.end()), id.end());

    for(auto& vec : v) {
        if(vec.empty()) continue;
        sort(vec.begin(), vec.end(), greater<int>());
    }

    for(int i=0; i<id.size(); i++) {
        int j = id[i];
        for(int k = 0; k < v[j].size(); k++) {
            sum[j][k+1] = sum[j][k] + v[j][k] + 2*k;
            pre[j][k+1] = pre[j][k] + v[j][k];
        }
    }

    for(int i=0; i<id.size(); i++) {
        for(int j=0; j<=K; j++) {
            for(int k=0; k<=v[id[i]].size(); k++) {
                if(j >= k) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j-k] + sum[id[i]][k]);
                }
            }
        }
    }

    cout << dp[id.size()][K] << "\n";

    return 0;
}