#include <iostream>
#include <cstdio>
#include <vector>

int main() {
    int n;
    std::scanf("%d", &n);

    int min = std::numeric_limits<int>::max();
    std::vector<int> A(n);

    for (int i = 0; i < n; i++) {
        std::scanf("%d", &A[i]);
        if (A[i] < min) {
            min = A[i];
        }
    }

    std::vector<int> count(10001, 0);
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    count[min]--;

    std::printf("%d", min);
    for (int i = min; i < 10001; i++) {
        for (int j = 0; j < count[i]; j++) {
            std::printf(" %d", i);
        }
    }
    std::printf("\n");

    return 0;
}