#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

const int N = 1e6;
bitset<N> is_prime;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  is_prime.set();  // set all bits to 1
  is_prime[0] = is_prime[1] = 0;
  int sqrt_N = sqrt(N);
  for (int i = 2; i <= sqrt_N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < N; j += i)
        is_prime[j] = 0;
    }
  }
  for (int i = 1; i < N; i++) {
    is_prime[i] += is_prime[i-1];
  }
  int n;
  while (cin >> n) {
    cout << is_prime[n] << '\n';
  }
  return 0;
}