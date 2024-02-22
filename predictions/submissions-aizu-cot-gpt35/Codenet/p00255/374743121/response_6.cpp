#include <iostream>
using namespace std;

void main() {
  for (;;) {
    long long n;
    cin >> n;
    if (!n)
      break;
    
    long long s = 0;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      s += a;
    }
    
    long long j[99999];
    for (long long i = n - 1; i >= 0; i--)
      cin >> j[i];
    
    sort(j, j + n);
    
    long long a = 0;
    for (long long i = n; i >= 0; i--)
      a = max((n--) * s, a);
    
    cout << a << endl;
  }
}