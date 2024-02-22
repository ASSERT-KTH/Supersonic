#include <iostream>
#include <vector>
#include <map>

using ll = long long;
const ll mod = 1000000009;

std::vector<ll> mul(const std::vector<std::vector<ll>>& A, const std::vector<ll>& b) {
    int n = A.size();
    std::vector<ll> ret(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i] += A[i][j] * b[j];
            ret[i] %= mod;
        }
    }
    return ret;
}

std::vector<std::vector<ll>> mul(const std::vector<std::vector<ll>>& A, const std::vector<std::vector<ll>>& B) {
    int n = A.size();
    std::vector<std::vector<ll>> C(n, std::vector<ll>(n, 0));
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

std::vector<std::vector<ll>> mat_pow(const std::vector<std::vector<ll>>& A, ll x) {
    int n = A.size();
    std::vector<std::vector<ll>> ret(n, std::vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        ret[i][i] = 1;
    }
    std::vector<std::vector<ll>> P(A);
    while (x) {
        if (x & 1)
            ret = mul(ret, P);
        P = mul(P, P);
        x >>= 1;
    }
    return ret;
}

int main() {
    int T = 1;
    int w, n;
    ll h;
    while (std::cin >> w >> h >> n, w) {
        std::map<ll, std::vector<int>> obj;
        for (int i = 0; i < n; ++i) {
            ll x, y;
            std::cin >> x >> y;
            --x;
            --y;
            if (y > 0) {
                obj[y].push_back(x);
            }
        }
        std::vector<std::vector<ll>> O(w, std::vector<ll>(w, 0));
        for (int i = 0; i < w; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (0 <= i + j && i + j < w)
                    O[i][i + j] = 1;
            }
        }
        std::vector<std::vector<ll>> A(w, std::vector<ll>(w, 0));
        for (int i = 0; i < w; ++i) {
            A[i][i] = 1;
        }
        ll ny = 0;
        for (const auto& p : obj) {
            ll Y = p.first;
            if (Y - ny > 1) {
                A = mul(mat_pow(O, Y - ny - 1), A);
            }
            std::vector<std::vector<ll>> B(O);
            for (int i : p.second) {
                for (int j = -1; j <= 1; ++j) {
                    if (0 <= i + j && i + j < w)
                        B[i][i + j] = 0;
                }
            }
            A = mul(B, A);
            ny = Y;
        }
        if (ny != h - 1)
            A = mul(mat_pow(O, h - 1 - ny), A);
        std::vector<ll> b(w, 0);
        b[0] = 1;
        std::vector<ll> res = mul(A, b);
        ll ans = res[w - 1];
        std::printf("Case %d: %lld\n", T++, ans);
    }
    return 0;
}