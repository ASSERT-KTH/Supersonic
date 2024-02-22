#include <iostream>
#include <unordered_set>

int main() {
    int n, q, cnt = 0;
    std::unordered_set<int> S;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        S.insert(x);
    }
    std::cin >> q;
    for (int j = 0; j < q; ++j) {
        int x;
        std::cin >> x;
        if (S.find(x) != S.end()) {
            ++cnt;
        }
    }
    std::cout << cnt << "\n";
    return 0;
}