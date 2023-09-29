#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int& val : a) std::cin >> val;

    std::sort(a.begin(), a.end());

    for (const int& val : a) std::cout << val << ' ';
    std::cout << '\n';

    return 0;
}