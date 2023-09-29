#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
const int MAXN = 100100;

int n, f[2][MAXN];
vector<int> b[2][MAXN];
bool v[MAXN];

int dfs(int s, int now, int maxi, int num) {
    v[now] = true;
    int res = num;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < b[i][now].size(); j++) {
            int nxt = b[i][now][j];
            if (!v[nxt]) {
                if (maxi == f[i][now])
                    res = (res + dfs(s, nxt, maxi, num)) % MOD;
                else if (maxi < f[i][now])
                    res = dfs(s, nxt, f[i][now], 1);
            }
        }
    }
    if (now == s && res == num)
        res++;
    return res;
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            int x, y, z, w;
            cin >> x >> y >> z >> w;
            b[0][x].push_back(z);
            b[1][x].push_back(z);
            f[0][x] = y;
            f[1][x] = w;
            v[x] = false;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                ans = (ans * dfs(i, i, 0, 0)) % MOD;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            b[0][i].clear();
            b[1][i].clear();
        }
    }
    return 0;
}