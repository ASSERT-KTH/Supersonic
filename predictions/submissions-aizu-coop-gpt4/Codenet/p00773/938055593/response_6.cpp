#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<int> tax(2000); // single vector instead of 2D vector
    int maxi = 0, i = 0, a, b;
    int hundredPlusX = 100 + x; // store the sum in a variable
    int hundredPlusY = 100 + y; // store the sum in a variable
    for (a = 1; a < s; ++a) {
      b = (s - (a * hundredPlusX) / 100 + 1) / (hundredPlusX / 100);
      int aTimesHundredPlusX = (a * hundredPlusX) / 100; // store the result in a variable
      int bTimesHundredPlusX = (b * hundredPlusX) / 100; // store the result in a variable
      if (aTimesHundredPlusX + bTimesHundredPlusX == s && b != 0) {
        tax[i++] = a; // pre-increment instead of post-increment
        tax[i++] = b; // pre-increment instead of post-increment
        maxi = max(maxi, (a * hundredPlusY) / 100 + (b * hundredPlusY) / 100);
      }
    }
    cout << maxi << endl;
  }
  return 0;
}