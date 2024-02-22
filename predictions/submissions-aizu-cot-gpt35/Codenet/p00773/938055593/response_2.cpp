#include <iostream>
#include <vector>
using namespace std;

int main() {
  int taxRate1, taxRate2, totalTax;
  while (cin >> taxRate1 >> taxRate2 >> totalTax) {
    if (totalTax == 0) {
      break;
    }
    
    vector<vector<int>> tax;
    int maxi = 0, i = 0, a = 1, b;
    while (a <= totalTax / 2) {
      b = (totalTax - (a * (100 + taxRate1)) / 100 + 1) * 100 / (100 + taxRate1);
      if ((a * (100 + taxRate1) + b * (100 + taxRate1)) == totalTax * 100 && b != 0) {
        tax.push_back({a, b});
        maxi = max(maxi, (tax[i][0] * (100 + taxRate2) + tax[i][1] * (100 + taxRate2)) / 100);
        i++;
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}