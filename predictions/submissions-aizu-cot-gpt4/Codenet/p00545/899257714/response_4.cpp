#include <iostream>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  ll A[100001];
  int D[100001];
  ll east[100001], west[100001];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
    if (D[i] == 1) {
      east[i] = i > 0 && D[i-1] == 1 ? A[i-1] : A[i];
      west[i] = MIN;
    } else {
      west[i] = i > 0 && D[i-1] == 2 ? A[i-1] : A[i];
      east[i] = MIN;
    }
  }
  int person;
  ll t;
  for (int i = 0; i < Q; i++) {
    cin >> person;
    person--;
    if (D[person] == 1) {
      t = (east[person] + A[person]) / 2;
      if (T < abs(t - A[person])) {
        cout << A[person] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      t = (west[person] + A[person]) / 2;
      if (T < abs(A[person] - t)) {
        cout << A[person] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }
  return 0;
}