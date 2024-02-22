#include <vector>
using namespace std;

int main(void) {
  vector<char> isPrime((51000 + 1) / 2, '\x01');
  isPrime[0] = '\0'; // 1 is not prime
  for (int i = 3; i * i <= 51000; i += 2) {
    if (isPrime[i / 2]) {
      for (int j = i * i; j <= 51000; j += 2 * i) {
        isPrime[j / 2] = '\0';
      }
    }
  }
  vector<int> primes;
  primes.emplace_back(2);
  for (int i = 3; i <= 51000; i += 2) {
    if (isPrime[i / 2])
      primes.emplace_back(i);
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++) {
      if (isPrime[(n - primes[i]) / 2])
        kotae++;
    }
    cout << kotae << endl;
  }
  return 0;
}