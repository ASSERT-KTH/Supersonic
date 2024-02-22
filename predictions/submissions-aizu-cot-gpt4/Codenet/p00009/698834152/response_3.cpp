#include <iostream>
#define MAX 999999
using namespace std;

int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];

int main() {
  int n;
  not_prime_flag[0] = not_prime_flag[1] = true;
  for (int i = 4; i <= MAX; i += 2) {
      not_prime_flag[i] = true;
  }
  for (int i = 3; i * i <= MAX; i += 2) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  num_prime[0] = num_prime[1] = 0;
  num_prime[2] = 1;
  for (int i = 3; i <= MAX; ++i) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}