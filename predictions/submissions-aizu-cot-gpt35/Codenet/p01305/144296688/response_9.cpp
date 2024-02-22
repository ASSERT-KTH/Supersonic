#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  for (int l = 0; l < n; l++) {
    double a, b;
    cin >> a >> b;
    
    double winrate1 = (a / (a + b));
    double winrate2 = (b / (a + b));
    
    cout << fixed;
    cout.precision(5);
    cout << winrate1 << " " << winrate2 << "\n";
  }
  
  return 0;
}