#include <iostream>
#include <vector>
#define MAX 999999
using namespace std;
vector<int> num_prime(MAX + 1, 0);
vector<bool> not_prime_flag(MAX + 1, false);
int main() {
  int n;
  for (int i = 2; i < MAX + 1; ++i) {
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