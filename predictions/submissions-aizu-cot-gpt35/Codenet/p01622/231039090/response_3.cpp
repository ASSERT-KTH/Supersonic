#include <iostream>
#include <vector>
#include <algorithm>

struct Book {
    int f;
    int s;
};

bool cmp(const Book& a, const Book& b) {
    return a.f > b.f;
}

int solve(const std::vector<Book>& books) {
    int sumf = 0, sums = 0;
    for (const auto& book : books) {
        sumf += book.f;
        sums += book.s;
    }
    if (2 * books[0].f <= sumf)
        return sumf + sums;

    int d = 2 * books[0].f - sumf;
    std::vector<int> dp(d + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < books.size(); i++) {
        for (int j = d - books[i].s; j >= 0; j--) {
            int temp = dp[j];
            dp[j + books[i].s] |= temp;
        }
    }

    int D = d;
    for (int i = d; i >= 0; i--) {
        if (dp[i]) {
            D = i;
            break;
        }
    }

    return sumf + sums + (d - D);
}

int main() {
    int n;
    while (std::cin >> n && n) {
        std::vector<Book> books(n);
        for (auto& book : books)
            std::cin >> book.f >> book.s;
        std::sort(books.begin(), books.end(), cmp);
        std::cout << solve(books) << std::endl;
    }
    return 0;
}