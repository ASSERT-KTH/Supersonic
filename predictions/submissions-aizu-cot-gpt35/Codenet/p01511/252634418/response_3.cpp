#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll mod = 1000000009;

using vl = vector<ll>;
using mat = vector<vl>;

mat matrixMultiply(const mat& A, const mat& B) {
    int n = A.size();
    mat C(n, vl(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

mat matrixExponentiation(const mat& A, ll x) {
    int n = A.size();
    mat ret(n, vl(n, 0));
    for (int i = 0; i < n; ++i) {
        ret[i][i] = 1;
    }
    mat P(A);
    while (x) {
        if (x & 1) {
            ret = matrixMultiply(ret, P);
        }
        P = matrixMultiply(P, P);
        x >>= 1;
    }
    return ret;
}

int main() {
    int T = 1;
    int w, n;
    ll h;
    while (cin >> w >> h >> n, w) {
        vector<vector<int>> obj(h, vector<int>());
        int maxX = 0;
        for (int i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            --x;
            --y;
            if (y > 0) {
                obj[y].push_back(x);
            }
            maxX = max(maxX, x);
        }
        mat O(w, vl(w, 0));
        for (int i = 0; i < w; ++i) {
            if (i - 1 >= 0) {
                O[i][i - 1] = 1;
            }
            O[i][i] = 1;
            if (i + 1 < w) {
                O[i][i + 1] = 1;
            }
        }
        mat A(w, vl(w, 0));
        for (int i = 0; i < w; ++i) {
            A[i][i] = 1;
        }
        ll ny = 0;
        for (int Y = 1; Y < h; ++Y) {
            if (obj[Y].empty()) {
                continue;
            }
            if (Y - ny > 1) {
                A = matrixMultiply(matrixExponentiation(O, Y - ny - 1), A);
            }
            mat B(O);
            for (int i : obj[Y]) {
                if (i - 1 >= 0) {
                    B[i][i - 1] = 0;
                }
                B[i][i] = 0;
                if (i + 1 < w) {
                    B[i][i + 1] = 0;
                }
            }
            A = matrixMultiply(B, A);
            ny = Y;
        }
        if (ny != h - 1) {
            A = matrixMultiply(matrixExponentiation(O, h - 1 - ny), A);
        }
        vl b(w, 0);
        b[0] = 1;
        vl res = matrixMultiply(A, b);
        ll ans = res[w - 1];
        printf("Case %d: %lld\n", T++, ans);
    }
    return 0;
}