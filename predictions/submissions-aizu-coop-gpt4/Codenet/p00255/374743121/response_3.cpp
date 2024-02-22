#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long *j = nullptr;
  long long n, s, a, old_n = 0;
  
  while (true) {
    cin >> n;
    
    if (n == 0)
      break;
      
    if (n != old_n) {
      delete[] j;
      j = new long long[n];
      old_n = n;
    }
      
    for (long long i = 0; i < n; i++) {
      cin >> j[i];
      if (i == 0) {
        s = a = j[i];
      } else {
        s += j[i];
      }
    }
      
    sort(j, j + n);
      
    for (; n > 0; n--) {
      a = max(n * s, a);
      s -= j[n - 1];
    }
      
    cout << a << endl;
  }
  
  delete[] j;
  
  return 0;
}