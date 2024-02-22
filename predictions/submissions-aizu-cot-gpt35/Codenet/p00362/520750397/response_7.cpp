#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long L;

vector<L> P, E, Z, H, C, A, O, X, B;
map<L, map<L, L>> T;

L k, n, a, b, c;

L sumOfBinaryDigits(L f) {
    L sum = 0;
    while (f) {
        sum += B[f];
        f ^= f & -f;
    }
    return sum;
}

void updateBinaryIndexedTree(L index, L value) {
    for (; index < 2e5; index += index & -index) {
        B[index] += value;
    }
}

void depthFirstSearch(L f) {
    Z[f] = 1;
    for (auto it = T[f].begin(); it != T[f].end(); it++) {
        L d = it->first;
        if (!Z[d]) {
            P[d] = f;
            E[d] = E[f] + 1;
            C[d] = it->second;
            depthFirstSearch(d);
            Z[f] += Z[d];
            if (!H[f] || Z[H[f]] < Z[d]) {
                H[f] = d;
            }
        }
    }
}

L calculateSum(L f) {
    L sum = 0;
    while (X[f] != X[b]) {
        a = X[f];
        n = X[b];
        sum += (A[a] + A[P[a]] + C[a]) % k ? (A[a] + A[P[a]] + C[a]) : 0;
        b = P[a];
    }
    sum += abs(sumOfBinaryDigits(O[f]) - sumOfBinaryDigits(O[b]));
    return sum;
}

int main() {
    cin >> n >> k;
    P.resize(n + 1);
    E.resize(n + 1);
    Z.resize(n + 1);
    H.resize(n + 1);
    C.resize(n + 1);
    A.resize(n + 1);
    O.resize(n + 1);
    X.resize(n + 1);
    B.resize(2e5 + 1);

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        T[a][b] = c;
        T[b][a] = c;
    }

    depthFirstSearch(1);

    for (int i = 1; i <= n; i++) {
        X[i] = n;
    }

    for (int i = 1; i <= n; i++) {
        for (a = H[P[i]]; !a || i; a = H[a]) {
            O[a] = ++b;
            updateBinaryIndexedTree(b, 1);
        }
        X[i] = i;
    }

    char s;
    while (cin >> s >> a >> b) {
        if (s & 2) {
            cout << calculateSum(a) << endl;
        } else {
            A[a] += b;
            updateBinaryIndexedTree(O[a], b);
        }
    }

    return 0;
}