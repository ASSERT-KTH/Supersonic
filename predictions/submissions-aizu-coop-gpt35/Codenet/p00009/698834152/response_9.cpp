#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;

bitset<MAX + 1> not_prime_flag;
int num_prime[MAX + 1];

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

  num_prime[0] = num_prime[1] = 0;
  for (int i = 2; i <= MAX; ++i) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }

  int n;
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }

  return 0;
}