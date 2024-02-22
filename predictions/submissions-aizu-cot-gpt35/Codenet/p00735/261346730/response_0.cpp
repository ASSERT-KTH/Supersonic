#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const int MAX_N = 300000;
    vector<int> primes;
    vector<bool> checked(MAX_N + 1, false);
    for (int i = 2; i <= MAX_N; i++) {
        if (checked[i]) continue;
        if (i % 7 == 1 || i % 7 == 6) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_N; j += i) {
                checked[j] = true;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1) break;
        vector<int> ans;
        for (auto p : primes) {
            if (p > sqrt(n)) break;
            if (n % p == 0) {
                ans.push_back(p);
            }
        }
        cout << n << ':';
        for (int i = 0; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
}