#include <iostream>
#define MAX 999999
using namespace std;

int prime_count[MAX + 1];

int main() {
  int n;
  
  // Calculate prime numbers and their count
  for (int i = 2; i <= MAX; ++i) {
    bool is_prime = true;
    
    // Check if i is prime
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    
    // Update prime count
    prime_count[i] = prime_count[i - 1] + (is_prime ? 1 : 0);
  }
  
  // Read input and output prime count
  while (cin >> n) {
    cout << prime_count[n] << endl;
  }
  
  return 0;
}