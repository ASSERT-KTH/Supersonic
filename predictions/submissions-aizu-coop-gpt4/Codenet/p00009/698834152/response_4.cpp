#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;

int num_prime[MAX + 1];
bitset<MAX + 1> not_prime_flag;

int main() {
  int n;
  for (int i = 2; i * i <= MAX; ++i) {  // only need to check up to sqrt(MAX)
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {  // start from i^2 and increment by i
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