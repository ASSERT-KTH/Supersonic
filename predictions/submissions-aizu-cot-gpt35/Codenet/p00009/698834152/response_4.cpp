#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;
bitset<MAX + 1> not_prime_flag;
int num_prime[MAX + 1];
int main() {
  for (int i = 2; i * i < MAX + 1; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j < MAX + 1; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  for (int i = 2; i < MAX + 1; ++i) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  int n;
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}