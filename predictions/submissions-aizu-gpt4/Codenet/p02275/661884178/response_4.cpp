#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
  
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int& a : A) {
        std::cin >> a;
    }
    std::sort(A.begin(), A.end());
    for (const int& a : A) {
        std::cout << a << ' ';
    }
    std::cout << '\n';
    return 0;
}