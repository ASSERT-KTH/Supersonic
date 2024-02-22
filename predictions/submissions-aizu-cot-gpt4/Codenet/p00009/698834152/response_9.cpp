#include <iostream>
#include <cmath>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
  int n;
  int limit = sqrt(MAX);
  for (int i = 2; i <= limit; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  int count = 0;
  for (int i = 2; i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      num_prime[i] = ++count;
    }
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}