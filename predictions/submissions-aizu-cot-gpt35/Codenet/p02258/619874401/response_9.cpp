#include <iostream>
using namespace std;
static const int MAX = 200000;
int main() {
  int n;
  cin >> n;
  int maxv = 0;
  int minv;
  cin >> minv;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    maxv = max(maxv, x - minv);
    minv = min(minv, x);
  }
  cout << maxv << endl;
  return 0;
}