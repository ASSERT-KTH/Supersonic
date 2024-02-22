#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string x;
  cin >> x;
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  for (int a = 0; a < x.length();) {
    if (x[a] != 'J') {
      a++;
    } else {
      for (; x[a] == 'J'; a++) {
        b++;
      }
      for (; x[a] == 'O'; a++) {
        c++;
      }
      for (; x[a] == 'I'; a++) {
        d++;
      }
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
      }
      b = c = d = 0;
    }
  }
  cout << maxi << "\n";
  return 0;
}