#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define INF 1e9
#define N 100000
using namespace std;
typedef long long ll;

int main() {
    int n, m, hp[101];
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> hp[i];
        vector<int> dmg[2], cost[2];
        cin >> m;
        for (int i = 0; i < m; i++) {
            string name, type;
            int c, d;
            cin >> name >> c >> type >> d;
            if (d)
                dmg[type == "All"].push_back(d), cost[type == "All"].push_back(c);
        }
        int max_dmg = *max_element(dmg[0].begin(), dmg[0].end());
        max_dmg = max(max_dmg, *max_element(dmg[1].begin(), dmg[1].end()));
        vector<int> dp[2];
        for (int i = 0; i < 2; i++) {
            dp[i].resize(max_dmg + 1, INF);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for (int j = 0; j < dmg[i].size(); j++)
                pq.push({cost[i][j], dmg[i][j]});
            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                dp[i][p.second] = min(dp[i][p.second], p.first);
                if (p.second < max_dmg)
                    pq.push({p.first + cost[i][p.second], p.second + dmg[i][p.second]});
            }
        }
        for (int i = 0; i < 2; i++)
            for (int j = max_dmg; j >= 0; j--)
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        ll ans = INF;
        for (int i = 0; i <= max_dmg; i++) {
            ll cost = dp[1][i];
            for (int j = 0; j < n; j++)
                cost += dp[0][max(0, hp[j] - i)];
            ans = min(ans, cost);
            if (cost < ans)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}