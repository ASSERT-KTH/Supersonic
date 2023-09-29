#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); // added to improve input/output speed
  cin.tie(NULL);
  cout.tie(NULL);
  int n, maxProfit = -1000000000, Ri = 2000000000;
  cin >> n;
  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    cin >> R[i];
    maxProfit = max(maxProfit, R[i] - Ri); // using max function instead of if condition
    Ri = min(Ri, R[i]); // using min function instead of if condition
  }
  cout << maxProfit << endl;
  return 0;
}