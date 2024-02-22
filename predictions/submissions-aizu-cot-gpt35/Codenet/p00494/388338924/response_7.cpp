#include <iostream>
#include <string>
using namespace std;

int main() {
  string x;
  x.resize(1000005, 'A');
  cin >> x;
  int leng = x.length();
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  while (a < leng) {
    switch (x[a]) {
      case 'J':
        b++;
        a++;
        break;
      case 'O':
        c++;
        a++;
        break;
      case 'I':
        d++;
        a++;
        break;
      default:
        a++;
        break;
    }
    if (b >= c && c <= d) {
      maxi = c;
    }
  }
  cout << maxi << endl;
  cin >> a;
  return 0;
}