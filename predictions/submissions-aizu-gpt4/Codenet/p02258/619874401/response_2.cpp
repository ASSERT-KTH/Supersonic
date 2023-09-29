#include <iostream>
#include <climits>

#define MAX 200000

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  
    int R[MAX], n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> R[i];

    int maxv = INT_MIN;
    int minv = R[0];
    for (int i = 1; i < n; ++i) {
        maxv = std::max(maxv, R[i] - minv);
        minv = std::min(minv, R[i]);
    }
    std::cout << maxv << '\n';
    return 0;
}