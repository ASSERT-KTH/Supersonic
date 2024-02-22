#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 300000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> primes;
    bitset<MAX_N + 1> checked;
    for (int i = 2; i <= sqrt(MAX_N); i++) {
        if (!checked[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_N; j += i) {
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
        for (auto p : primes) {
            if (n % p == 0) {
                factors.push_back(p);
            }
        }
        
        cout << n << ':';
        for (int i = 0; i < factors.size(); i++) {
            cout << ' ' << factors[i];
        }
        cout << endl;
    }

    return 0;
}