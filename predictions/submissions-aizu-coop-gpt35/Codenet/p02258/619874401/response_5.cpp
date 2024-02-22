#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int* R;
  int n;
  cin >> n;
  R = new int[n];
  for (int i = 0; i < n; i++)
    cin >> R[i];
  int maxv = R[1] - R[0];
  int minv = R[0];
  int diff;
  for (int i = 1; i < n; i++) {
    diff = R[i] - minv;
    maxv = max(maxv, diff);
    minv = min(minv, R[i]);
  }
  cout << maxv << endl;
  delete[] R;
  return 0;
}