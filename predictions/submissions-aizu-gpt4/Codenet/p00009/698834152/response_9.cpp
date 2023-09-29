#include <iostream>
#include <vector>
#include <cmath>

#define MAX 999999

using namespace std;

vector<int> num_prime(MAX + 1);
vector<bool> not_prime_flag(MAX + 1);

int main() {
  int n;
  int upperLimit = static_cast<int>(sqrt(MAX));
  for (int i = 2; i <= upperLimit; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  for (int i = 2; i <= MAX; ++i) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}