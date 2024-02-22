#include <iostream>
#define MAX 999999
using namespace std;
bool not_prime_flag[MAX + 1];

int count_primes(int n) {
  int count = 0;
  for (int i = 2; i <= n; ++i) {
    count += !not_prime_flag[i];
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i * i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  int n;
  while (cin >> n) {
    cout << count_primes(n) << '\n';
  }
  return 0;
}