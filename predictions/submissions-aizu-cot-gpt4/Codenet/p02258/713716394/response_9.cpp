#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> R;
  R.reserve(n);
  
  int maxProfit = 1 - 1000000000;
  int Ri = R[0];
  
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    R.push_back(temp);
    
    if (i == 0) {
      Ri = R[0];
    }
    else {
      if (maxProfit < R[i] - Ri) {
        maxProfit = R[i] - Ri;
      }
      if (R[i] < Ri) {
        Ri = R[i];
      }
    }
  }
  
  cout << maxProfit << endl;
  
  return 0;
}