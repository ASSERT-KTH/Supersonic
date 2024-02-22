#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;

bitset<MAX + 1> not_prime_flag;

int main() {
  int n;

  // Calculate the count of prime numbers on the fly
  int prime_count = 0;
  for (int i = 2; i < MAX + 1; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = 2; i * j < MAX + 1; ++j) {
        not_prime_flag[i * j] = true;
      }
      prime_count++;
    }
  }

  // Enable compiler optimizations
  #pragma GCC optimize("unroll-loops")

  while (cin >> n) {
    // Print the count of prime numbers up to n
    int count = 0;
    for (int i = 2; i <= n; ++i) {
      if (!not_prime_flag[i]) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}