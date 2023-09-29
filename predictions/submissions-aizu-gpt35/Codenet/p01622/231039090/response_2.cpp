#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1005;
int n, sumf, sums;
P book[MAXN];
bool dp[3005];
int solve() {
    sumf = sums = 0;
    for (int i = 0; i < n; i++)
        sumf += book[i].f, sums += book[i].s;
    if (2 * book[0].f <= sumf)
        return sumf + sums;
    int d = 2 * book[0].f - sumf, D = d;
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = D - book[i].s; j >= 0; j--)
            if (dp[j])
                dp[j + book[i].s] = true;
    while (!dp[D])
        D--;
    return sumf + sums + (d - D);
}
int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> book[i].f >> book[i].s;
        sort(book, book + n, greater<P>());
        cout << solve() << endl;
    }
    return 0;
}