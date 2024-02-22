#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;

int num_prime[MAX + 1];
bitset<MAX + 1> not_prime_flag;
int cumulative_prime[MAX + 1];

#pragma GCC optimize("unroll-loops")
int main() {
  for (int i = 2; i < MAX + 1; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = 2; i * j < MAX + 1; ++j) {
        not_prime_flag[i * j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
    cumulative_prime[i] = cumulative_prime[i - 1] + num_prime[i];
  }

  int n;
  while (cin >> n) {
    cout << cumulative_prime[n] << endl;
  }
  return 0;
}