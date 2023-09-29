#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int& t : A) {
    cin >> t;
  }

  sort(A.begin(), A.end());

  for (const int& i : A) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}