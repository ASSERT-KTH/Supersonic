#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 1001;
int n;
P book[MAX_N];
int solve() {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++) {
        sumf += book[i].f;
        sums += book[i].s;
    }
    if (2 * book[0].f <= sumf) {
        return sumf + sums;
    }
    int d = 2 * book[0].f - sumf;
    const int MAX_D = 3000;
    vector<bool> dp(MAX_D + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = d - book[i].s; j >= 0; j--) {
            dp[j + book[i].s] = dp[j + book[i].s] || dp[j];
        }
    }
    int D = d;
    while (!dp[D]) {
        D--;
    }
    return sumf + sums + (d - D);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> book[i].f >> book[i].s;
        }
        sort(book, book + n, greater<P>());
        cout << solve() << '\n';
    }
    return 0;
}