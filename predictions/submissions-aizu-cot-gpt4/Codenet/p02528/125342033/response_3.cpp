#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, i, f;
  int A[1000001];
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> A[i];
  
  sort(A, A + n);
  
  stringstream output;
  for (i = f = 0; i < n; i++)
    output << (f ? " " : "") << A[i], f = 1;
  
  cout << output.str() << '\n';
}