#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define int long long
typedef vector<int> vi;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back

const int MAX = 300000;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  // Generate prime numbers using segmented sieve
  vector<bool> prime(MAX + 1, true);
  set<int> primes;
  for (int p = 2; p * p <= MAX; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= MAX; i += p) {
        prime[i] = false;
      }
    }
  }
  for (int p = 2; p <= MAX; p++) {
    if (prime[p]) {
      primes.insert(p);
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cout << num << ':';
    for (int p : primes) {
      if (num % p == 0) {
        cout << " " << p;
      }
    }
    cout << endl;
  }
}