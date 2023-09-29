#include <stdio.h>
#include <unordered_map>
typedef long long ll;
const ll a[2] = { 101, 103 };
const ll M[2] = { 1000000007, 1000000009 };
ll d[2][300010], k[2][300010];
ll h[2], hh[2], p[300010][2];
int L[300010], R[300010];
char s[300010], q[5];
std::unordered_map<ll, int> mp;
int main() {
    int n = 0, m, i, j, l = 0, r = 1;
    scanf("%*d %d %s", &m, s);
    for (i = 0; i < 2; i++) {
        k[i][0] = p[0][i] = 1;
        for (j = d[i][0] = 0; s[j]; j++) {
            d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
            k[i][j + 1] = (k[i][j] * a[i]) % M[i];
            p[j + 1][i] = k[i][j + 1];
        }
    }
    for (i = 0; i < m; i++) {
        scanf("%s", q);
        if (q[0] == 'L')
            l += q[1] - '-' ? 1 : -1;
        else
            r += q[1] - '-' ? 1 : -1;
        L[i] = l, R[i] = r;
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < 2; j++) {
            h[j] = (d[j][R[i]] - d[j][L[i]] * k[j][R[i] - L[i]]) % M[j];
            hh[j] = (h[j] * p[L[i]][j] % M[j] + M[j]) % M[j];
        }
        mp[hh[0] << 32 | hh[1]]++;
    }
    printf("%d\n", m - (int)mp.size());
    return 0;
}