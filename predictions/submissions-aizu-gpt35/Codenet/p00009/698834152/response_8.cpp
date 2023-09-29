#include <iostream>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
  ios_base::sync_with_stdio(false); // added line
  cin.tie(NULL); // added line
  int n;
  for (int i = 2; i * i <= MAX; ++i) { // optimized loop condition
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) { // optimized inner loop
        not_prime_flag[j] = true;
      }
    }
  }
  for (int i = 2; i <= MAX; ++i) { // optimized loop
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}