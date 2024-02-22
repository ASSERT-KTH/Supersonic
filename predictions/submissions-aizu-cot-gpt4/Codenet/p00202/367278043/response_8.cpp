#include <iostream>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool prime[MAX + 1];
vector<bool> dp(MAX + 1, false);

void sieve() {
    int root = sqrt(MAX);
    fill(prime, prime + MAX + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= root; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int n, x;
    while (cin >> n >> x, n) {
        set<int> a;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a.insert(temp);
        }
        dp[0] = true;
        for (int i = 1; i <= x; i++) {
            for (auto j : a) {
                if (i >= j && dp[i - j]) {
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
    return 0;
}