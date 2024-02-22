#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  int min = 2000000, t;
  map<int, int> A;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  cout << min;
  for (int i = min; i <= A.rbegin()->first; i++) {
    for (int j = 0; j < A[i]; j++) {
      cout << ' ' << i;
    }
  }
  cout << '\n';
  return 0;
}