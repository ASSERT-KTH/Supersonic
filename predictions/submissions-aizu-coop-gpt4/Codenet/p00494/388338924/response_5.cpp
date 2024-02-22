#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string x;
  cin >> x;

  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  int leng = x.size();

  for (a = 0; a < leng; a++) {
    if (x[a] == 'J') {
      b = 0;
      while (x[a] == 'J' && a < leng) {
        b++;
        a++;
      }
      c = 0;
      while (x[a] == 'O' && a < leng) {
        c++;
        a++;
      }
      d = 0;
      while (x[a] == 'I' && a < leng) {
        d++;
        a++;
      }
      a--; // adjust a back to the last valid position
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
      }
    }
  }

  cout << maxi << "\n";
  return 0;
}