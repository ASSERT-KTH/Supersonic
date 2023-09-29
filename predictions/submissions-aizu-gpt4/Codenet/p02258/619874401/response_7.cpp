#include <iostream>
#include <limits>
using namespace std;
static const int MAX = 200000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int R[MAX], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> R[i];
  int maxv = R[1] - R[0];
  int minv = R[0];
  for (int i = 2; i < n; i++) {
    minv = min(minv, R[i - 1]);
    maxv = max(maxv, R[i] - minv);
  }
  cout << maxv << "\n";
  return 0;
}