#include <iostream>
using namespace std;

int main() {
  int interestRate1, interestRate2, s;
  while (cin >> interestRate1 >> interestRate2 >> s && (interestRate1 || interestRate2 || s)) {
    int tax[1000][2];
    int maxTax = 0;
    int taxCount = 0;
    int a = 1, b;
    while (a < s) {
      b = (s - (a * (100 + interestRate1)) / 100 + 1) / ((100 + interestRate1) / 100);
      if (((a * (100 + interestRate1)) / 100 + (b * (100 + interestRate1)) / 100) == s && b != 0) {
        tax[taxCount][0] = a;
        tax[taxCount][1] = b;
        maxTax = max(maxTax, (tax[taxCount][0] * (100 + interestRate2)) / 100 +
                             (tax[taxCount][1] * (100 + interestRate2)) / 100);
        taxCount++;
      }
      a++;
    }
    cout << maxTax << endl;
  }
  return 0;
}