#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, f, A[1000001];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> A[i];
    std::sort(A, A + n);
    for (int i = 0, f = 0; i < n; i++)
        std::cout << (f++ ? " " : "") << A[i];
    std::cout << '\n';
    return 0;
}