#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> P;

int solve(vector<P>& book, int n) {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++)
        sumf += book[i].first, sums += book[i].second;

    int d = 2 * book[0].first - sumf;
    vector<int> dp(d + 1, 0);
    dp[0] = 1;
    int D = d;
    for (int i = 1; i < n; i++)
        for (int j = d - book[i].second; j >= 0; j--)
            dp[j + book[i].second] |= dp[j];
    while (!dp[D])
        D--;
    return sumf + sums + (d - D);
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<P> book(n);
        for (int i = 0; i < n; i++)
            cin >> book[i].first >> book[i].second;
        sort(book.begin(), book.end(), greater<P>());
        cout << solve(book, n) << endl;
    }
    return 0;
}