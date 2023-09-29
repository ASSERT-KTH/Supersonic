#include <stdio.h>
#define MAX_N 300010
#define MOD1 1000000007LL
#define MOD2 1000000009LL
#define BASE 101LL

typedef long long int ll;

ll n, m;
char s[MAX_N];
ll h[2][MAX_N], p[2][MAX_N];
int main() {
    scanf("%lld %lld %s", &n, &m, s);
    p[0][0] = p[1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            h[j][i + 1] = (h[j][i] * BASE % (j == 0 ? MOD1 : MOD2) + s[i]) % (j == 0 ? MOD1 : MOD2);
            p[j][i + 1] = p[j][i] * BASE % (j == 0 ? MOD1 : MOD2);
        }
    }
    ll l = 0, r = 1, cnt = 0;
    for (int i = 0; i < m; i++) {
        char op[5];
        scanf("%s", op);
        if (op[0] == 'L') {
            l -= (op[1] == '+' ? 1 : -1);
        } else {
            r += (op[1] == '+' ? 1 : -1);
        }
        ll lh1 = (h[0][l] + MOD1 - h[0][0] * p[0][l] % MOD1) % MOD1;
        ll rh1 = (h[0][n] - h[0][r - 1] * p[0][n - r + 1] % MOD1 + MOD1) % MOD1;
        ll lh2 = (h[1][l] + MOD2 - h[1][0] * p[1][l] % MOD2) % MOD2;
        ll rh2 = (h[1][n] - h[1][r - 1] * p[1][n - r + 1] % MOD2 + MOD2) % MOD2;
        if (lh1 * p[1][MAX_N - 1] + lh2 == rh1 * p[1][MAX_N - 1] + rh2) {
            cnt++;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}