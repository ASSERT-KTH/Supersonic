#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, f, A[1000001];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> A[i];
  
  sort(A, A + n);

  for (int i = 0, f = 0; i < n; i++)
    cout << (f ? " " : "") << A[i], f = 1;

  cout << '\n';
  return 0;
}