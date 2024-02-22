#include <iostream>
#include <cstring>

double a[101][101];
double memo[101][101][101];

double solve(int total, int remaining, int current, int next) {
    if (remaining == 1)
        return 1;
    if (memo[current][remaining][next] > 0)
        return memo[current][remaining][next];
    double result = 0;
    for (int i = 0; i < total; ++i) 
        result = std::max(result, solve(total, remaining - 1, current, i) * a[current][i]);
    return memo[current][remaining][next] = result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int total, remaining;
    double result;
    while (std::cin >> total >> remaining, total | remaining) {
        std::memset(memo, 0, sizeof(memo));
        for (int i = 0; i < total; ++i) 
            for (int j = 0; j < total; ++j) 
                std::cin >> a[i][j];
        result = 0;
        for (int i = 0; i < total; ++i) 
            for (int j = 0; j < total; ++j) 
                result = std::max(result, solve(total, remaining, i, j));
        std::cout << result << "\n";
    }
    return 0;
}