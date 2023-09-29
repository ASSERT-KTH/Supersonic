#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<int> b(m);
  
    for (auto& row : a) {
        for (auto& item : row) {
            std::cin >> item;
        }
    }
  
    for (auto& item : b) {
        std::cin >> item;
    }
  
    for (const auto& row : a) {
        int c = 0;
        for (size_t j = 0; j < m; ++j) {
            c += row[j] * b[j];
        }
        std::cout << c << '\n';
    }
    return 0;
}