#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto& row : a)
        for (auto& element : row)
            std::cin >> element;

    std::vector<int> b(m);
    for (auto& element : b)
        std::cin >> element;

    for (const auto& row : a) {
        int c = 0;
        for (int j = 0; j < m; ++j)
            c += row[j] * b[j];
        std::cout << c << '\n';
    }

    return 0;
}