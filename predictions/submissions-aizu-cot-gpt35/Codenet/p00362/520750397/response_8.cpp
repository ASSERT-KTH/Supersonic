#include <iostream>
#include <map>
using namespace std;

typedef long long L;

L P[32768] = {}, E[32768] = {}, C[32768] = {}, A[32768] = {}, k, n, a, b;

L M(L f) {
    L res = 0;
    while (f) {
        res += A[f];
        f ^= f & -f;
    }
    return res;
}

void D(L f) {
    L d;
    for (const auto& elem : T[f]) {
        d = elem.first;
        if (!Z[d]) {
            P[d] = f;
            E[d] = E[f] + 1;
            C[d] = elem.second;
            D(d);
            Z[f] += Z[d];
            if (!H[f] || Z[H[f]] < Z[d]) {
                H[f] = d;
            }
        }
    }
}

L K(L f) {
    a = X[f];
    n = X[b];
    return a - n ? M(O[E[a] < E[n] ? a = n, n = b, b = f, n : f]) + K(P[a]) : abs(M(O[f]) - M(O[b]));
}

int main() {
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        T[a][b] = T[b][a] = c;
    }
    D(a = b = 0);
    for (n = 1; n <= *Z; n++) {
        for (; !b || a; a = H[a], O[a] = ++b) {
            X[a] = n;
        }
    }
    while (scanf("%lld", &a) != EOF) {
        scanf(" %c %lld %lld", &s, &a, &b);
        if (*s & 2) {
            printf("%lld\n", K(a));
        } else {
            A[a] += b;
        }
    }
    return 0;
}