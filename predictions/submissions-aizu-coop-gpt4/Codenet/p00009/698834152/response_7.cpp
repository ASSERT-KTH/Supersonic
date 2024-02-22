#include <iostream>
#include <bitset>

#define MAX 999999

using namespace std;

// Using bitset instead of an array of bools.
bitset<MAX + 1> not_prime_flag;
int num_prime[MAX + 1];

int main() {
  int n;

  not_prime_flag[0] = not_prime_flag[1] = true;

  for (int i = 2; i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      // Skip even numbers.
      for (int j = i * 2; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }

  while (cin >> n) {
    cout << num_prime[n] << endl;
  }

  return 0;
}