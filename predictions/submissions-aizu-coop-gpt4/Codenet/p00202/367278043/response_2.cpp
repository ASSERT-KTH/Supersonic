#include <algorithm>
#include <iostream>
using namespace std;

int n, x;
int* a;
bool* dp;
bool* prime;

void generatePrimes(int limit) {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> x, n) {
        a = new int[n];
        dp = new bool[x + 1]();
        prime = new bool[x + 1]();

        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);

        fill_n(prime, x + 1, true);
        generatePrimes(x);

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

        delete[] a;
        delete[] dp;
        delete[] prime;
    }

    return 0;
}