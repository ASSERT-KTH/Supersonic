#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;
vector<bool> prime(MAX, true);

// Function to precompute prime numbers
void computePrimes() {
  prime[0] = false;
  prime[2] = true;
  
  for (int i = 3; i <= MAX; i += 2)
    prime[i] = true;
  
  for (int i = 3; i * i <= MAX; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j <= MAX; j += 2 * i)
        prime[j] = false;
    }
  }
}

int main() {
  int n, x;
  
  // Precompute prime numbers
  computePrimes();
  
  while (cin >> n >> x, n) {
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
      cin >> a[i];
    
    // Optimized dynamic programming approach
    vector<bool> dp(x + 1, false);
    dp[0] = true;
    
    for (int i = 0; i < n; i++) {
      for (int j = x; j >= a[i]; j--) {
        if (dp[j - a[i]])
          dp[j] = true;
      }
    }
    
    // Find the largest prime number
    int largestPrime = -1;
    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        largestPrime = i;
        break;
      }
    }
    
    if (largestPrime != -1)
      cout << largestPrime << endl;
    else
      cout << "NA" << endl;
  }
  
  return 0;
}