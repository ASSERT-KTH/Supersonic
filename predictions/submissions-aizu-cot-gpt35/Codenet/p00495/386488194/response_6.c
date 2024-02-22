#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    int x;
    while (std::cin >> x) {
        int m = 0, u = 0;
        for (int i = 0; i < n; i++) {
            int t = u;
            u = (x != c[i]) ? u : m + 1;
            m = std::max(m, u);
        }
        std::cout << m << '\n';
    }
    
    return 0;
}