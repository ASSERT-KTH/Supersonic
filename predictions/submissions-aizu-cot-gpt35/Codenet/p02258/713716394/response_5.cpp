#include <iostream>
using namespace std;

int main() {
  int n;
  int maxProfit = INT_MIN;
  int Ri = INT_MAX;
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int R;
    cin >> R;
    
    maxProfit = max(maxProfit, R - Ri);
    Ri = min(Ri, R);
  }
  
  cout << maxProfit << endl;
  
  return 0;
}