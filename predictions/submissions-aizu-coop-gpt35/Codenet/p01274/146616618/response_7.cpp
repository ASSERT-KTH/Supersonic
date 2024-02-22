#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e9
#define N 100000
using namespace std;

struct Attack {
    int type;
    int cost;
    int damage;
};

int main() {
    int n, m;
    while (scanf("%d", &n), n) {
        int* hp = new int[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &hp[i]);

        vector<Attack> mg;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            Attack attack;
            string type;
            cin >> attack.cost >> type >> attack.damage;
            attack.type = (type == "All") ? 1 : 0;
            if (attack.damage)
                mg.push_back(attack);
        }

        int dp[2][N + 10];
        memset(dp, INF, sizeof(dp));

        for (int i = 0; i < mg.size(); i++) {
            for (int j = mg[i].damage; j <= (N / mg[i].damage + 1) * mg[i].damage; j++) {
                dp[mg[i].type][min(N, j)] = min(dp[mg[i].type][min(N, j)], dp[mg[i].type][j - mg[i].damage] + mg[i].cost);
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = N; j >= 0; j--) {
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }

        int ans = INF;
        for (int i = 0; i <= N; i++) {
            int cost = dp[1][i];
            for (int j = 0; j < n; j++) {
                cost += dp[0][max(0, hp[j] - i)];
            }
            ans = min(ans, cost);
        }

        printf("%d\n", ans);

        delete[] hp;
    }
    return 0;
}