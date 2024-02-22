#include <iostream>
#include <cmath>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int limit = sqrt(MAX + 1);
  for (int i = 2; i <= limit; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j < MAX + 1; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  num_prime[2] = 1;
  for (int i = 3; i < MAX + 1; ++i) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}