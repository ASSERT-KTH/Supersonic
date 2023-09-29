#include <iostream>
#define MAX 999999
using namespace std;
int num_prime[MAX];
bool not_prime_flag[MAX];
int main() {
  int n;
  for (int i = 1; i < MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = 2; (i + 1) * j - 1 < MAX; ++j) {
        not_prime_flag[(i + 1) * j - 1] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  while (cin >> n) {
    cout << num_prime[n - 1] << endl;
  }
  return 0;
}
