#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
const int MAXN = 100100;

int n, f[MAXN][2], ans = 1;
bool v[MAXN];
vector<int> e[MAXN][2];

void dfs(int u, int s, int maxi, int &num) {
    v[u] = true;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < e[u][i].size(); ++j) {
            int v = e[u][i][j];
            if (!v[v]) {
                if (maxi == f[v][i]) {
                    num++;
                } else if (maxi < f[v][i]) {
                    maxi = f[v][i];
                    num = 1;
                }
                if (v == s) {
                    ans = ans * (num + 1) % MOD;
                    return;
                }
                dfs(v, s, maxi, num);
            }
        }
    }
    if (maxi == f[s][1]) {
        ans = ans * (num + 1) % MOD;
    } else if (maxi < f[s][1]) {
        ans = ans * 2 % MOD;
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i) {
            cin >> e[i][0] >> f[i][0] >> e[i][1] >> f[i][1];
            v[i] = false;
        }
        ans = 1;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                int num = 1;
                dfs(i, e[i][0][0], f[i][0], num);
            }
        }
        cout << ans << endl;
    }
    return 0;
}