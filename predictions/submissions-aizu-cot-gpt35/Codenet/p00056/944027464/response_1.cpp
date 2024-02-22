#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {
  const int MAX = 51000;
  bitset<MAX + 1> isPrime;
  isPrime.set();
  
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  
  vector<int> primes;
  for (int i = 2; i <= MAX; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
  
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int left = 0, right = primes.size() - 1;
    
    while (left <= right) {
      int sum = primes[left] + primes[right];
      if (sum == n) {
        kotae++;
        left++;
        right--;
      } else if (sum < n) {
        left++;
      } else {
        right--;
      }
    }
    
    cout << kotae << endl;
  }
  
  return 0;
}