#include <stdio.h>
#include <cmath>
#include <vector>

int main() {
    constexpr int N = 1000000;
    std::vector<int> num(N, 1);
    num[0] = num[1] = 0;
    int limit = static_cast<int>(std::sqrt(N));

    for (int i = 2; i <= limit; ++i) {
        if (num[i] == 1) {
            for (int j = i * i; j < N; j += i)
                num[j] = 0;
        }
    }

    for (int i = 1; i < N - 1; ++i) {
        num[i + 1] += num[i];
    }

    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", num[n]);
    }
    return 0;
}