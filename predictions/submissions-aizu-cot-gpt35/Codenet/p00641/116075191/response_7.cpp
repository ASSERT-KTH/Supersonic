#include <cstdio>
#include <cstring>

int dfs(int s, int now, int maxi, int num, int n, int b[][100100], int f[][100100], bool v[]) {
    v[now] = true;
    for (int i = 0; i < 2; i++) {
        if (!v[b[i][now]]) {
            if (maxi == f[i][now])
                num++;
            else if (maxi < f[i][now]) {
                maxi = f[i][now];
                num = 1;
            }
            if (b[i][now] == s)
                return num;
            return dfs(s, b[i][now], maxi, num, n, b, f, v);
        }
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
    while (scanf("%d", &n), n) {
        int b[2][100100];
        int f[2][100100];
        bool v[100100];
        memset(v, false, sizeof(v));

        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &b[0][i], &f[0][i], &b[1][i], &f[1][i]);
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                v[i] = true;
                int result = dfs(i, b[0][i], f[0][i], 1, n, b, f, v);
                ans = (ans * result) % 10007;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}