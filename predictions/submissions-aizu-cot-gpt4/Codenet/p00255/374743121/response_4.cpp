#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  for (long long n, s = 0, a, max_val = 0;; cout << max_val << endl) {
    cin >> n;
    if (!n)
      break;
    long long* j = new long long[n]; // dynamically allocate array
    for (long long i = 0; i < n; i++) {
      cin >> a; // read number
      s += a; // add to sum
      j[i] = a; // store number into array
    }
    sort(j, j + n); // sort array
    for (long long i = n - 1; i >= 0; i--) {
      max_val = max(n * s, max_val); // calculate maximum value
      s -= j[i]; // subtract from sum
      n--; // decrement n
    }
    delete[] j; // free memory
  }
  return 0;
}