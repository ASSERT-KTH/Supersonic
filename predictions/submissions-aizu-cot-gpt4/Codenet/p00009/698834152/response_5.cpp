#include <iostream>
#include <bitset>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bitset<MAX+1> not_prime_flag;
int main() {
  int n;
  num_prime[2] = 1;
  for (int i = 3; i < MAX + 1; i += 2) {
    if (!not_prime_flag[i]) {
      for (int j = i; (long long)j * i < MAX + 1; j += 2) {
        not_prime_flag[i * j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
    if(i+1 <= MAX) num_prime[i+1] = num_prime[i]; // handle even numbers
  }
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}