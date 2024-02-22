#include <iostream>
#define MAX 999999
using namespace std;
bool not_prime_flag[MAX + 1];

int main() {
  int n;
  for (int i = 2; i * i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i; i * j <= MAX; j += 2) {
        not_prime_flag[i * j] = true;
      }
    }
  }
  while (cin >> n) {
    int prime_count = 0;
    for (int i = 2; i <= n; ++i) {
      prime_count += !not_prime_flag[i];
    }
    cout << prime_count << endl;
  }
  return 0;
}