#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const int MAX_NUM = 300000;
    const int MAX_PRIME = sqrt(MAX_NUM) + 1;

    bitset<MAX_NUM + 1> checked;
    vector<int> primes;

    for (int i = 2; i < MAX_PRIME; i++) {
        if (!checked[i]) {
            if (i % 7 == 1 || i % 7 == 6) {
                primes.push_back(i);
                for (int j = i * i; j <= MAX_NUM; j += i) {
                    checked[j] = true;
                }
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;
        vector<int> divisors;
        for (int p : primes) {
            if (n % p == 0) {
                divisors.push_back(p);
            }
        }
        cout << n << ':';
        for (int i : divisors) {
            cout << ' ' << i;
        }
        cout << '\n';
    }

    return 0;
}