#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e6;
vector<int> primes(MAX+1, 0);
vector<bool> is_prime(MAX+1, true);
int main() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i*i <= MAX; ++i) {
    if (is_prime[i]) {
      for (int j = i*i; j <= MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for(int i=2; i<=MAX; ++i){
    primes[i] = primes[i-1] + is_prime[i];
  }
  int n;
  while (cin >> n) {
    cout << primes[n] << endl;
  }
  return 0;
}