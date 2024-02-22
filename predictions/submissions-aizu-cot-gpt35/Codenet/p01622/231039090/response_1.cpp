#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int main() {
    int n;
    while (cin >> n, n) {
        vector<P> book(n);
        for (int i = 0; i < n; i++)
            cin >> book[i].first >> book[i].second;
        
        sort(book.begin(), book.end(), greater<P>());
        
        int sumf = 0, sums = 0;
        for (int i = 0; i < n; i++) {
            sumf += book[i].first;
            sums += book[i].second;
        }
        
        if (2 * book[0].first <= sumf) {
            cout << sumf + sums << endl;
            continue;
        }
        
        int d = 2 * book[0].first - sumf;
        vector<int> dp(d + 1, 0);
        dp[0] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = d - book[i].second; j >= 0; j--) {
                dp[j + book[i].second] |= dp[j];
                if (dp[d])
                    break;
            }
        }
        
        int D = d;
        while (!dp[D])
            D--;
        
        cout << sumf + sums + (d - D) << endl;
    }
    return 0;
}