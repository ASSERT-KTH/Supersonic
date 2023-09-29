#include <iostream>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
  int n;
  for (int i = 2; i < MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = 2; i * j < MAX + 1; ++j) {
        not_prime_flag[i * j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}
