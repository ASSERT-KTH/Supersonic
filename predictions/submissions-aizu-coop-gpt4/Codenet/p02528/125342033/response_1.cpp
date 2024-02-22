#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false); // Disable synchronization
    std::cin.tie(NULL); // Untie cin from cout

    int n;
    std::cin >> n;

    int A[1000001];
    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    std::sort(A, A + n);

    for (int i = 0; i < n; i++)
        std::cout << A[i] << (i < n - 1 ? " " : "\n");
}