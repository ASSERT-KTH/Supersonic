#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> A(n);

  for (int i = 0; i < n; i++)
    cin >> A[i];

  sort(A.begin(), A.end());

  for (int i = 0; i < n; i++)
    cout << A[i] << ' ';

  cout << '\n';

  return 0;
}