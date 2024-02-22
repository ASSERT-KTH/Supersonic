#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> R(n);
  
  // initialize Ri and maxProfit to the first input value and 0 respectively
  cin >> R[0];
  int Ri = R[0];
  int maxProfit = 0;
  
  // combine input reading and profit calculation into one loop
  for (int i = 1; i < n; i++) {
    cin >> R[i];
    maxProfit = max(maxProfit, R[i] - Ri);
    Ri = min(Ri, R[i]);
  }

  cout << maxProfit << endl;
  
  return 0;
}