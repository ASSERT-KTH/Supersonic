#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int* R = new int[n];
  for (int i = 0; i < n; i++)
    cin >> R[i];

  int maxv = (R[1] > R[0]) ? (R[1] - R[0]) : 0;
  
  for (int i = 1; i < n; i++) {
    if (R[i] - R[i-1] > 0) {
      maxv = max(maxv, R[i] - R[i-1]);
    }
  }

  cout << maxv << endl;

  delete[] R;
  return 0;
}