#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int min = 2000000, t;
  vector<int> A(10001, 0);
  
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t < min)
      min = t;
    A[t]++;
  }
  
  stringstream ss;
  ss << min;
  for (int i = min; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) {
      ss << ' ' << i;
    }
  }
  
  cout << ss.str() << endl;
  return 0;
}