#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class StaticRMQ {
    T *a;
    std::vector<std::vector<uint32_t>> table;
    std::vector<uint32_t> R, L, part;

public:
    StaticRMQ(std::vector<T>& array) {
        a = new T[array.size()];
        R.resize((array.size() + 31) / 32);
        L.resize((array.size() + 31) / 32);
        part.resize(array.size());
        table.resize(32);

        for (uint32_t i = 0; i < array.size(); ++i) {
            a[i] = array[i];
            part[i] = 1 << (i % 32);
            if (i % 32 == 0) {
                R[i / 32] = 1;
            }
            for (uint32_t j = 0; j < i; ++j) {
                if (!(array[i] < array[j])) {
                    part[i] |= part[j];
                    break;
                }
            }
            if (array[i] < a[i / 32]) {
                R[i / 32] |= 1 << (i % 32);
            }
            if (i % 32 == 31) {
                L[i / 32] = part[i];
            }
        }

        for (uint32_t t = 0; t < 31; ++t) {
            table[t].resize(array.size() - (1 << t) + 1);
            for (uint32_t m = 0; m < array.size() - (1 << t) + 1; ++m) {
                table[t][m] = a[table[t - 1][m]] < a[table[t - 1][m + (1 << (t - 1))]]
                    ? table[t - 1][m]
                    : table[t - 1][m + (1 << (t - 1))];
            }
        }
    }

    uint32_t operator()(uint32_t begin, uint32_t end) {
        uint32_t l = (begin / 32) + 1;
        uint32_t r = (end - 1) / 32;
        if (l < r) {
            uint32_t t = std::__lg(r - l + 1);
            t = std::min(a[table[t][l]], a[table[t][r - (1 << t) + 1]]);
            t = std::min(a[(begin & ~31) | __builtin_ctz(L[begin / 32] & ((1 << (begin % 32)) - 1))], t);
            return std::min(a[(end & ~31) | (31 - __builtin_clz(R[end / 32] & (-1 << (end % 32))))], t);
        }
        if (l == r) {
            uint32_t t = a[(begin & ~31) | __builtin_ctz(L[begin / 32] & ((1 << (begin % 32)) - 1))];
            return std::min(a[(end & ~31) | (31 - __builtin_clz(R[end / 32] & (-1 << (end % 32))))], t);
        }
        return a[(end & ~31) | __builtin_ctz(part[end] & ((1 << (begin % 32)) - 1))];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    uint32_t n, l;
    std::cin >> n >> l;

    std::vector<uint32_t> a(n);
    for (uint32_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    StaticRMQ<uint32_t> S(a);
    std::cout << S(0, l);
    for (uint32_t i = 1; i < n - l + 1; ++i) {
        std::cout << " " << S(i, i + l);
    }
    std::cout << "\n";

    delete[] S.a;
    return 0;
}