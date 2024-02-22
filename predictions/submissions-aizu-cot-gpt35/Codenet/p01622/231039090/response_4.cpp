#include <iostream>
#include <algorithm>
#include <vector>

struct Book {
    int f;
    int s;
};

int solve(int n, std::vector<Book>& books) {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++)
        sumf += books[i].f, sums += books[i].s;
    if (2 * books[0].f <= sumf)
        return sumf + sums;
    int d = 2 * books[0].f - sumf;
    std::vector<bool> dp(d + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = d - books[i].s; j >= 0; j--) {
            dp[j + books[i].s] |= dp[j];
        }
    }
    int D = d;
    while (!dp[D])
        D--;
    return sumf + sums + (d - D);
}

int main() {
    int n;
    while (std::cin >> n && n) {
        std::vector<Book> books(n);
        for (int i = 0; i < n; i++)
            std::cin >> books[i].f >> books[i].s;
        std::partial_sort(books.begin(), books.begin() + n, books.end(),
                          [](const Book& b1, const Book& b2) {
                              return b1.f + b1.s > b2.f + b2.s;
                          });
        std::cout << solve(n, books) << std::endl;
    }
    return 0;
}