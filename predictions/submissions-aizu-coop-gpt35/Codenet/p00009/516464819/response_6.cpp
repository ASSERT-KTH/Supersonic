#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes) {
  vector<bool> is_prime(n + 1, true);
  
  // Calculate the square root of n only once
  int sqrt_n = sqrt(n);
  
  for (int i = 3; i <= sqrt_n; i += 2) {
    if (!is_prime[i])
      continue;
      
    // Increment by 2*i instead of i*2
    for (int j = i * i, skip = i + i; j <= n; j += skip)
      is_prime[j] = false;
  }
  
  primes.push_back(2);
  
  for (int i = 3; i <= n; i += 2)
    if (is_prime[i])
      primes.push_back(i);
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  
  int x;
  while (cin >> x)
    inputs.push_back(x);
  
  int max_input = *max_element(inputs.begin(), inputs.end());
  sieve(max_input, primes);
  
  for (int x : inputs) {
    int count = 0;
    
    for (int p : primes) {
      if (p == x) {
        count++;
        break;
      } else if (p > x) {
        break;
      } else {
        count++;
      }
    }
    
    cout << count << endl;
  }
  
  return 0;
}