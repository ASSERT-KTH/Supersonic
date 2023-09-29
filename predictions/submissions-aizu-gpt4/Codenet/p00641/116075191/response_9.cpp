#include <iostream>
#include <vector>
using namespace std;

vector<int> b[2], f[2];
vector<bool> v;
int n;

int dfs(int s, int now, int maxi, int num) {
    v[now] = true;
    for (int i = 0; i < 2; ++i) {
        if (!v[b[i][now]]) {
            num = max(maxi < f[i][now] ? (maxi = f[i][now], 1) : (maxi == f[i][now], num + 1), num);
            if (b[i][now] == s)
                return num;
            num = dfs(s, b[i][now], maxi, num);
        }
    }
    return max(maxi < f[1][s] ? 1 : (maxi == f[1][s], num + 1), num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n, n) {
        b[0].resize(n); f[0].resize(n); b[1].resize(n); f[1].resize(n); v.resize(n, false);
        for (int i = 0; i < n; ++i) 
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
        
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                v[i] = true;
                ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}