#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_SIZE = 2e5 + 1;
const int MAX_K = 7 << 15;

vector<pair<int, int>> T[MAX_SIZE];
int P[MAX_SIZE], E[MAX_SIZE], Z[MAX_SIZE], H[MAX_SIZE], C[MAX_SIZE], A[MAX_SIZE], O[MAX_SIZE], X[MAX_SIZE], B[MAX_SIZE];
int k, n, a, b, c;

inline int M(int f) {
    int res = 0;
    while (f) {
        res += B[f];
        f ^= f & -f;
    }
    return res;
}

inline void S(int a, int i) {
    for (; i < MAX_SIZE; i += i & -i) {
        B[i] += a;
    }
}

void D(int f) {
    stack<int> stk;
    Z[f] = 1;
    stk.push(f);
    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();
        for (auto& p : T[curr]) {
            int d = p.first;
            if (!Z[d]) {
                P[d] = curr;
                E[d] = E[curr] + 1;
                C[d] = p.second;
                Z[d] = 1;
                stk.push(d);
                Z[f] += Z[d];
                if (!H[f] || Z[H[f]] < Z[d]) {
                    H[f] = d;
                }
            }
        }
    }
}

int K(int f) {
    int res = 0;
    int a = X[f];
    int b = X[b];
    while (a - b) {
        int tmp = O[E[a] < E[b] ? a : b];
        res += M(O[E[a] < E[b] ? a = b, b = f, f] + O[a]);
        res -= M(O[f] + O[b]);
        f = P[a];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        T[a].push_back({ b, c });
        T[b].push_back({ a, c });
    }

    D(0);

    int q;
    char s;
    cin >> q;
    while (q--) {
        cin >> s >> a >> b;
        if (s & 2) {
            cout << K(a) << endl;
        } else {
            S(H[a], ++O[a]);
            S(H[a], O[a] - 1);
            A[a] += b;
        }
    }

    return 0;
}