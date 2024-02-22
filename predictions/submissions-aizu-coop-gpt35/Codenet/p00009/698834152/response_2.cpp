#include <iostream>
#include <cstring>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
  memset(not_prime_flag, false, sizeof(not_prime_flag));

  #pragma GCC optimize("unroll-loops")
  #pragma GCC optimize("O3")
  #pragma GCC target("avx,avx2,fma")
  
  int n;
  for (int i = 3; i * i < MAX + 1; i += 2) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j < MAX + 1; j += i * 2) {
        not_prime_flag[j] = true;
      }
    }
  }

  num_prime[2] = 1;
  for (int i = 3; i < MAX + 1; i += 2) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }

  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}