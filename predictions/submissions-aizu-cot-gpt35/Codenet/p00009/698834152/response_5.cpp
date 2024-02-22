#include <iostream>

#define MAX 999999

int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;

  for (int i = 2; i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = 2; i * j <= MAX; ++j) {
        not_prime_flag[i * j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + 1 - not_prime_flag[i];
  }

  for (std::cin >> n; !std::cin.eof(); std::cin >> n) {
    std::cout << num_prime[n] << '\n';
  }

  return 0;
}