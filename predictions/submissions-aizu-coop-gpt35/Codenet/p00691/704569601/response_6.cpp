#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int z;
  while (cin >> z && z) {
    int ans = 0;
    for (int x = 1; x * x * x <= z * z * z; x++) {
      int x3 = x * x * x; // Store x^3 in a variable
      int y = max(ans - x3, 1); // Start y from the previous value of y instead of 1
      while (y * y * y + x3 <= z * z * z) {
        int y3 = y * y * y; // Store y^3 in a variable
        ans = max(ans, x3 + y3);
        y++;
      }
    }
    cout << z * z * z - ans << endl;
  }
}