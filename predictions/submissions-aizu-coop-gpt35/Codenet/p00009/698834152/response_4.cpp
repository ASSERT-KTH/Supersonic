#include <iostream>
#include <bitset>
using namespace std;

#define MAX 999999

int main() {
  int n;
  bitset<MAX + 1> not_prime_flag;
  int count = 0;

  for (int i = 2; i <= n; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i; i * j <= n; ++j) {
        not_prime_flag[i * j] = true;
      }
      count++;
    }
  }

  while (cin >> n) {
    cout << count << endl;
  }

  return 0;
}