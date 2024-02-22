#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int n;
  cin >> n;
  int min = 2000000, t, A[10001];
  memset(A, 0, sizeof(A));
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  cout << min;
  for (int i = min; i < 10001; i++) {
    for (int j = 0; j < A[i]; j++) {
      cout << ' ' << i;
    }
  }
  cout << endl;
  return 0;
}