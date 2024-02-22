#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    const int limit = 300000;
    
    bitset<limit+1> isPrime;
    vector<int> primes;
    
    for (int i = 2; i <= limit; i++) {
        if (!isPrime[i]) {
            if (i % 7 == 1 || i % 7 == 6) {
                primes.push_back(i);
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = true;
                }
            }
        }
    }
    
    while (true) {
        int n;
        cin >> n;
        
        if (n == 1)
            break;
        
        vector<int> ans;
        
        for (auto p : primes) {
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
    
    return 0;
}