#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;

  while (cin >> x >> y >> s && (x || y || s)) {
    vector<int> revenue(s + 1, 0); // stores the maximum revenue for each amount 's'
    
    for (int a = 1; a <= s; a++) {
      int b = (s - a * (100 + x) / 100) * 100 / (100 + x);
      
      if (a + b == s && b != 0) {
        int taxA = a * (100 + y) / 100;
        int taxB = b * (100 + y) / 100;
        int totalRevenue = taxA + taxB;
        
        revenue[s] = max(revenue[s], totalRevenue);
      }
    }
    
    cout << revenue[s] << endl;
  }

  return 0;
}