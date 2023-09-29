#include <iostream>
#include <limits>
using namespace std;
static const int MAX = 200000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int R[MAX], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> R[i];
  int maxv = -numeric_limits<int>::max();
  int minv = R[0];
  for (int i = 1; i < n; i++) {
    maxv = max(maxv, R[i] - minv);
    minv = min(minv, R[i]);
  }
  cout << maxv << endl;
  return 0;
}