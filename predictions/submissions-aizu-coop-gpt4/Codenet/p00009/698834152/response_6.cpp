#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;
bitset<MAX + 1> not_prime_flag;
int main() {
  int n;
  int num_prime = 0;
  for (int i = 2; i * i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
    if (!not_prime_flag[i]) num_prime++;
  }
  while (cin >> n) {
    cout << num_prime << endl;
  }
  return 0;
}