#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];

int solve() {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++)
        sumf += book[i].first, sums += book[i].second;

    if (2 * book[0].first <= sumf)
        return sumf + sums;

    int d = 2 * book[0].first - sumf;
    vector<bool> dp(d + 1);
    dp[0] = true;

    for (int i = 1; i < n; i++)
        for (int j = d - book[i].second; j >= 0; j--)
            dp[j + book[i].second] |= dp[j];

    while (!dp[d])
        d--;

    return sumf + sums + (2 * book[0].first - sumf - d);
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> book[i].first >> book[i].second;

        sort(book, book + n, greater<P>());
        cout << solve() << endl;
    }
    return 0;
}