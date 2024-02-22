#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void SieveOfEratosthenes(vector<bool>& prime) {
    int n = prime.size();
    fill(prime.begin(), prime.end(), true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> prime(1000001);
    SieveOfEratosthenes(prime);

    int n, x;
    while (cin >> n >> x, n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        vector<bool> dp(x+1, false);
        dp[0] = true;
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < n && i >= a[j]; j++) {
                if (dp[i - a[j]]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        for (int i = x; i >= 0; i--) {
            if (dp[i] && prime[i]) {
                cout << (i ? to_string(i) : "NA") << "\n";
                break;
            }
        }
    }
}