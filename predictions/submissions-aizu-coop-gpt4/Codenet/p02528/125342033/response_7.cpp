#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  for (int i = 0; i < n; i++)
    cout << (i ? " " : "") << A[i];
  cout << "\n";
  return 0;
}