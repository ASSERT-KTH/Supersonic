#include <iostream>
#define MAX 999999
using namespace std;
short num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
  num_prime[0] = num_prime[1] = 0;
  for (int i = 2; i < MAX + 1; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i; i * j < MAX + 1; ++j) {
        not_prime_flag[i * j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  int n;
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}