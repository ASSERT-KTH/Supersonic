#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> R;
  R.reserve(n);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    R.push_back(temp);
  }
  int maxv = R[1] - R[0];
  int minv = R[0];
  for (int i = 1; i < n; i++) {
    maxv = max(maxv, R[i] - minv);
    if (R[i] < minv)
      minv = R[i];
  }
  cout << maxv << '\n';
  return 0;
}