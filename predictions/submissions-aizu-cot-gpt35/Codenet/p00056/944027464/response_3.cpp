#include <vector>

int main(void) {
  std::vector<bool> isPrime(51001, false);
  isPrime[2] = true;
  for (int i = 3; i <= 51000; i += 2) {
    isPrime[i] = true;
  }
  std::vector<int> primes;
  primes.reserve(51000 / 2);
  int kotae = 0;
  for (int i = 3; i <= 51000; i += 2) {
    if (isPrime[i]) {
      primes.push_back(i);
      kotae++;
      for (int j = i + i; j <= 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  int n;
  while (std::cin >> n) {
    if (n == 0) {
      break;
    }
    int count = 0;
    for (int i = 0; i < kotae; i++) {
      if (primes[i] <= n / 2 && isPrime[n - primes[i]]) {
        count++;
      }
    }
    std::cout << count << std::endl;
  }
  return 0;
}