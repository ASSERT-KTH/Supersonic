#include <iostream>
#include <vector>
using namespace std;

const int N = 51000;
vector<bool> isPrime(N+1, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
        if(isPrime[i]) {
            for(int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
    int n;
    while(cin >> n && n != 0) {
        int kotae = 0;
        for(int i = 0; primes[i] <= n / 2; ++i) {
            if(isPrime[n - primes[i]]) {
                ++kotae;
            }
        }
        cout << kotae << endl;
    }
    return 0;
}