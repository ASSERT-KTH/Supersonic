#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int MAX = 300000;
    
    vector<int> primeList;
    bool checked[MAX + 1] = {};
    
    for (int i = 2; i <= MAX; i++) {
        if (checked[i]) continue;
        
        primeList.push_back(i);
        for (int j = i * i; j <= MAX; j += i) {
            checked[j] = true;
        }
    }
    
    while (true) {
        int n;
        cin >> n;
        if (n == 1) break;
        
        vector<int> factors;
        for (int p : primeList) {
            if (n % p == 0) {
                factors.push_back(p);
            }
        }
        
        cout << n << ':';
        for (int factor : factors) {
            cout << ' ' << factor;
        }
        cout << '\n';
    }
    
    return 0;
}