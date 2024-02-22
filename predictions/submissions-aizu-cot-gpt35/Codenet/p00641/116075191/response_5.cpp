#include <iostream>
using namespace std;

int dfs(int s, int now, int maxi, int num, bool v[], int b[][100100], int f[][100100]) {
    v[now] = true;
    while (true) {
        bool found = false;
        for (int i = 0; i < 2; i++) {
            if (!v[b[i][now]]) {
                found = true;
                if (maxi == f[i][now])
                    num++;
                else if (maxi < f[i][now]) {
                    maxi = f[i][now];
                    num = 1;
                }
                if (b[i][now] == s)
                    return num;
                now = b[i][now];
                break;
            }
        }
        if (!found) break;
    }
    if (maxi == f[1][s])
        return num + 1;
    else if (maxi < f[1][s])
        return 1;
    else
        return num;
}

int main() {
    int n;
    int b[2][100100];
    int f[2][100100];
    bool v[100100];
    
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
            v[i] = false;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                v[i] = true;
                ans = (ans * dfs(i, b[0][i], f[0][i], 1, v, b, f)) % 10007;
            }
        }
        cout << ans << endl;
    }
}