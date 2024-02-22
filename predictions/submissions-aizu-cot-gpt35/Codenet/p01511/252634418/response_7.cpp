#include <iostream>
#include <vector>

const long long mod = 1000000009;

std::vector<std::vector<long long>> matrix_multiply(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
    int n = A.size();
    std::vector<std::vector<long long>> C(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

std::vector<std::vector<long long>> matrix_pow(const std::vector<std::vector<long long>>& A, long long x) {
    int n = A.size();
    std::vector<std::vector<long long>> ret(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        ret[i][i] = 1;
    }
    std::vector<std::vector<long long>> P(A);
    while (x) {
        if (x & 1) {
            ret = matrix_multiply(ret, P);
        }
        P = matrix_multiply(P, P);
        x >>= 1;
    }
    return ret;
}

std::vector<long long> matrix_vector_multiply(const std::vector<std::vector<long long>>& A, const std::vector<long long>& b) {
    int n = A.size();
    std::vector<long long> ret(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i] = (ret[i] + A[i][j] * b[j]) % mod;
        }
    }
    return ret;
}

int main() {
    int T = 1;
    int w, n;
    long long h;
    while (std::cin >> w >> h >> n, w) {
        std::vector<std::vector<int>> obj(w);
        for (int i = 0; i < n; ++i) {
            long long x, y;
            std::cin >> x >> y;
            --x;
            --y;
            if (y > 0) {
                obj[y].push_back(x);
            }
        }
        std::vector<std::vector<long long>> O(w, std::vector<long long>(w, 0));
        for (int i = 0; i < w; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (0 <= i + j && i + j < w) {
                    O[i][i + j] = 1;
                }
            }
        }
        std::vector<std::vector<long long>> A(w, std::vector<long long>(w, 0));
        for (int i = 0; i < w; ++i) {
            A[i][i] = 1;
        }
        long long ny = 0;
        for (int p = 0; p < w; ++p) {
            if (obj[p].empty()) {
                continue;
            }
            long long Y = p;
            if (Y - ny > 1) {
                A = matrix_multiply(matrix_pow(O, Y - ny - 1), A);
            }
            std::vector<std::vector<long long>> B(O);
            for (int i : obj[p]) {
                for (int j = -1; j <= 1; ++j) {
                    if (0 <= i + j && i + j < w) {
                        B[i][i + j] = 0;
                    }
                }
            }
            A = matrix_multiply(B, A);
            ny = Y;
        }
        if (ny != h - 1) {
            A = matrix_multiply(matrix_pow(O, h - 1 - ny), A);
        }
        std::vector<long long> b(w, 0);
        b[0] = 1;
        std::vector<long long> res = matrix_vector_multiply(A, b);
        long long ans = res[w - 1];
        std::printf("Case %d: %lld\n", T++, ans);
    }
    return 0;
}