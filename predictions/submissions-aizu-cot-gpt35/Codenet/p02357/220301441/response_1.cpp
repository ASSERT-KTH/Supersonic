#include <iostream>
#include <vector>

class StaticRMQ {
    std::vector<int> a;
    std::vector<std::vector<int>> table;

public:
    StaticRMQ(const std::vector<int>& array) : a(array) {
        int n = array.size();
        int logn = 32 - __builtin_clz(n);
        table.resize(logn, std::vector<int>(n));

        for (int i = 0; i < n; ++i) {
            table[0][i] = i;
        }

        for (int k = 1; (1 << k) <= n; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                int x = table[k - 1][i];
                int y = table[k - 1][i + (1 << (k - 1))];
                table[k][i] = (a[x] < a[y]) ? x : y;
            }
        }
    }

    int operator()(int begin, int end) {
        int k = 31 - __builtin_clz(end - begin + 1);
        int x = table[k][begin];
        int y = table[k][end - (1 << k) + 1];
        return (a[x] < a[y]) ? a[x] : a[y];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, l;
    std::cin >> n >> l;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    StaticRMQ S(a);
    std::cout << S(0, l);

    for (int i = 1; i < n - l + 1; ++i) {
        std::cout << " " << S(i, i + l);
    }

    std::cout << "\n";

    return 0;
}