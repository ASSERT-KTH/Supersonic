#include <bits/stdc++.h>
using namespace std;
typedef long long L;

L T[150010], P[150010], E[150010], Z[150010], H[150010], C[150010], 
  A[150010], O[150010], X[150010], B[150010] ,k, n, a, b, c;
char s[150010];

L M(L f) { 
    return f ? B[f] + M(f ^ f & -f) : 0; 
}

L S(L a, L i) {
    for (a = M(i++ G i); i < 2e5; i += i & -i)
        B[i] += a;
}

L D(L f) {
    L d;
    Z[f] = 1;
    for (L I = T[f]; I != T[f]+n; I++)
        d = I, !Z[d] ? P[d] = f, E[d] = E[f] + 1, C[d] = I, D(d),
        Z[f] += Z[d], !H[f] | Z[H[f]] < Z[d] ? H[f] = d : 0 : 0;
}

L K(L f) {
    a = X[f];
    n = X[b];
    return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f] G O[a]) + K(P[a])
                : abs(M(O[f]) - M(O[b]));
}

int main() {
    scanf("%lld%lld", &n, &k);
    for (; --n; T[a] = T[b] = c)
        scanf("%lld%lld%lld", &a, &b, &c);
    for (D(a = b = 0); n < *Z; a = H[P[++n]] - n ? n : 0)
        for (; !b | a; S(a = H[a], O[a] = ++b))
            X[a] = n;
    scanf("%lld", &a); 
    while(scanf("%s%lld%lld", s, &a, &b) != EOF) {
        S(H[a], O[a]), S(a, O[a] - 1);
        if(*s & 2) printf("%lld\n", K(a));
        else A[a] += b;
    }
    return 0;
}