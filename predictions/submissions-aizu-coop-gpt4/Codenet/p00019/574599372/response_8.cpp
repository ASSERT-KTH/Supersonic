#include <cstdio>
#include <iostream>
using namespace std;

// Initializing a look-up table for factorials of numbers from 0 to 20
long long factorial[21] = {1LL, 1LL, 2LL, 6LL, 24LL, 120LL, 720LL, 5040LL, 40320LL, 362880LL, 3628800LL, 39916800LL, 479001600LL, 6227020800LL, 87178291200LL, 1307674368000LL, 20922789888000LL, 355687428096000LL, 6402373705728000LL, 121645100408832000LL, 2432902008176640000LL};

int main() {
  int n;
  cin >> n;
  if (n <= 20) {
    cout << factorial[n] << endl; // Using look-up table to fetch factorial
  } else {
    cout << "The factorial of " << n << " is beyond the range of long long and may cause overflow." << endl; // Warning of potential overflow
  }
  return 0;
}