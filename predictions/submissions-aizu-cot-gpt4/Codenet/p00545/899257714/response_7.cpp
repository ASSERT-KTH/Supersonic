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
  ll east, west, t;
  ll results[1001];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    int people;
    cin >> people;
    people--;
    if (D[people] == 1) {
      east = A[people];
      for (ll j = people + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < abs(t - A[people])) {
        results[i] = A[people] + T;
      } else {
        results[i] = t;
      }
    } else {
      west = A[people];
      for (ll j = people - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      if (T < abs(A[people] - t)) {
        results[i] = A[people] - T;
      } else {
        results[i] = t;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    cout << results[i] << endl;
  }
  return 0;
}