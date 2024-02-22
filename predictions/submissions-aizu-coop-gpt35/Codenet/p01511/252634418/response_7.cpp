#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll mod = 1000000009;

using vl = vector<ll>;
using mat = vector<vl>;

mat mat_mul(const mat& A, const mat& B) {
    int n = A.size();
    mat C(n, vl(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                C[i][j] += (A[i][k] * B[k][j]) % mod;
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

mat mat_pow(const mat& A, ll x) {
    int n = A.size();
    mat ret(n, vl(n, 0));
    for (int i = 0; i < n; ++i) {
        ret[i][i] = 1;
    }
    mat P(A);
    while (x) {
        if (x & 1)
            ret = mat_mul(ret, P);
        P = mat_mul(P, P);
        x >>= 1;
    }
    return ret;
}

int main() {
    int T = 1;
    int w, n;
    ll h;
    while (cin >> w >> h >> n, w) {
        vector<vector<bool>> obj(h, vector<bool>(w, false));
        for (int i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            --x;
            --y;
            if (y > 0) {
                obj[y][x] = true;
            }
        }
        mat O(w, vl(w, 0));
        for (int i = 0; i < w; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (0 <= i + j && i + j < w) {
                    O[i][i + j] = 1;
                }
            }
        }
        mat A(w, vl(w, 0));
        for (int i = 0; i < w; ++i) {
            A[i][i] = 1;
        }
        ll ny = 0;
        for (int Y = 1; Y < h; ++Y) {
            if (Y - ny > 1) {
                A = mat_mul(mat_pow(O, Y - ny - 1), A);
            }
            for (int i = 0; i < w; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (0 <= i + j && i + j < w && obj[Y][i + j]) {
                        A[i][i + j] = 0;
                    }
                }
            }
            ny = Y;
        }
        if (ny != h - 1) {
            A = mat_mul(mat_pow(O, h - 1 - ny), A);
        }
        vector<ll> b(w, 0);
        b[0] = 1;
        vector<ll> res(w, 0);
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                res[i] += (A[i][j] * b[j]) % mod;
                res[i] %= mod;
            }
        }
        ll ans = res[w - 1];
        printf("Case %d: %lld\n", T++, ans);
    }
    return 0;
}