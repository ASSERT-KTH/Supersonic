#include <iostream>
using namespace std;

int main() {
  int tax_x, tax_y, sum;
  while (cin >> tax_x >> tax_y >> sum && (tax_x || tax_y || sum)) {
    int max_tax = 0;
    for (int a = 1; a < sum; a++) {
      int b = (sum - (a * (100 + tax_x) / 100)) * 100 / (100 + tax_x);
      if ((a * (100 + tax_x) + b * (100 + tax_x)) == sum * (100 + tax_x) &&
          b != 0) {
        int tax_amount = (a * (100 + tax_y) + b * (100 + tax_y)) / 100;
        max_tax = max(max_tax, tax_amount);
      }
    }
    cout << max_tax << endl;
  }
  return 0;
}