#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // disable synchronization
  cin.tie(NULL); // untie cin and cout

  int n, i, f;
  int A[1000001];
  
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> A[i];

  std::sort(A, A + n);

  for (i = f = 0; i < n; i++)
    cout << (f ? " " : "") << A[i], f = 1;

  cout << "\n";

  return 0;
}