#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int min = INT_MAX;
  vector<int> A(10001, 0);
  
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  
  cout << min;
  for (int i = min; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) {
      cout << ' ' << i;
    }
  }
  cout << '\n';
  
  return 0;
}