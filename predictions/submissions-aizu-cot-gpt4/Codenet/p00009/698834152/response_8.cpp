#include <iostream>
#define MAX 999999
using namespace std;

int prime_counts[MAX + 1];

void calculate_prime_counts() {
  bool not_prime_flag;
  for (int i = 2; i * i <= MAX; ++i) {
    if (prime_counts[i] == i) { // i is prime
      for (int j = i; i * j <= MAX; ++j) {
        if (prime_counts[i * j] == i * j) { // if this number hasn't been marked yet
          prime_counts[i * j] = i;
        }
      }
    }
  }
  for (int i = 3; i <= MAX; ++i) {
    prime_counts[i] = prime_counts[i - 1] + (prime_counts[i] == i);
  }
}

int main() {
  calculate_prime_counts();
  int n;
  while (cin >> n) {
    cout << prime_counts[n] << endl;
  }
  return 0;
}