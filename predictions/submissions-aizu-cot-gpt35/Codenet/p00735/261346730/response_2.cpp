#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const int MAX_NUM = 300000;
    vector<int> primes;
    bitset<MAX_NUM + 1> checked;

    for (int i = 2; i <= MAX_NUM; i++) {
        if (checked[i])
            continue;
        if (i % 7 == 1 || i % 7 == 6) {
            primes.push_back(i);
            for (int j = i; j <= MAX_NUM; j += i) {
                checked[j] = true;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;
        vector<int> factors;
        for (int p : primes) {
            if (n % p == 0) {
                factors.push_back(p);
            }
        }
        cout << n << ':';
        for (int i = 0; i < factors.size(); i++) {
            cout << " " << factors[i];
        }
        cout << endl;
    }

    return 0;
}