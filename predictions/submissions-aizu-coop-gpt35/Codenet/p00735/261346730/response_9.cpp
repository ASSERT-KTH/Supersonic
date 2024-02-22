#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  
  const int N = 300000;
  vector<int> primes;
  bitset<N> isPrime;

  for (int i = 2; i <= N; i++) {
    if (!isPrime[i]) {
      if (i % 7 == 1 || i % 7 == 6) {
        primes.push_back(i);
        for (int j = i * i; j <= N; j += i) {
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
    for (int p : primes) {
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
    
    cout << n << ':';
    for (int i : ans) {
      cout << ' ' << i;
    }
    cout << endl;
  }
  return 0;
}