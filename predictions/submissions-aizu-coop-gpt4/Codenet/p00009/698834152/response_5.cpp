#include <iostream>
#include <vector>
#include <cmath>
#define MAX 999999
using namespace std;
vector <bool> is_prime(MAX + 1, true);
vector <int> primes;
int main() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= sqrt(MAX); ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= MAX; j += i)
        is_prime[j] = false;
    }
  }
  for (int i = 2; i <= MAX; ++i)
    if (is_prime[i])
      primes.push_back(i);

  int n;
  while (cin >> n) {
    auto it = upper_bound(primes.begin(), primes.end(), n);
    cout << distance(primes.begin(), it) << endl;
  }
  return 0;
}