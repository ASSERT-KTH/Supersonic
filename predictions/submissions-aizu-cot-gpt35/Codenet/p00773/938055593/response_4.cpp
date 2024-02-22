#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int xPlus100 = 100 + x;
    int yPlus100 = 100 + y;
    int maxi = 0, i = 0, a = 1, b;
    while (a < s) {
      int axPlus100 = (a * xPlus100) / 100;
      b = (s - axPlus100 + 1) / (xPlus100 / 100);
      if ((a + b) * xPlus100 == s * 100) {
        vector<vector<int>> tax(i + 1, vector<int>(2));
        tax[i][0] = a;
        tax[i][1] = b;
        int tax0yPlus100 = (tax[i][0] * yPlus100) / 100;
        int tax1yPlus100 = (tax[i][1] * yPlus100) / 100;
        maxi = max(maxi, tax0yPlus100 + tax1yPlus100);
        i++;
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}