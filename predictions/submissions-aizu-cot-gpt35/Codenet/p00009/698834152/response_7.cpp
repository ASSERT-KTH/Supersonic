#include <iostream>
#define MAX 999999
using namespace std;

short num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];

int main() {
  int n;

  for (int i = 3; i <= MAX; i += 2) {
    if (!not_prime_flag[i]) {
      for (int j = i; i * j <= MAX; ++j) {
        not_prime_flag[i * j] |= true;
      }
    }
    num_prime[i] = num_prime[i - 1] + not_prime_flag[i] == 0;
  }

  while (cin >> n) {
    cout << num_prime[n] << endl;
  }

  return 0;
}