#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<pair<int, int>> book(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> book[i].first >> book[i].second;
            sum += book[i].first;
            sum += book[i].second;
        }
        sort(book.begin(), book.end());

        int d = book[0].first;
        vector<int> dp(3000, 0);
        dp[0] = 1;
        int D = d;
        for (int i = 1; i < n; i++) {
            for (int j = d - book[i].second; j >= 0; j--) {
                dp[j + book[i].second] |= dp[j];
            }
        }
        while (!dp[D]) {
            D--;
        }
        cout << sum + (d - D) << endl;
    }
    return 0;
}