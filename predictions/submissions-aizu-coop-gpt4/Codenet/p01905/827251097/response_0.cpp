#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::cout << n - m - 1 << '\n';
    return 0;
}