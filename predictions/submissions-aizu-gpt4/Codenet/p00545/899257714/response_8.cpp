#include <iostream>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  ll* A = new ll[N];
  int* D = new int[N];
  ll* people = new ll[Q];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  ll east = MIN;
  ll west = MIN;
  ll t;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      for (int j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << "\n";
      } else {
        cout << t << "\n";
      }
    } else {
      west = A[people[i]];
      for (int j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      if (T < abs(A[people[i]] - t)) {
        cout << A[people[i]] - T << "\n";
      } else {
        cout << t << "\n";
      }
    }
  }
  delete[] A;
  delete[] D;
  delete[] people;
  return 0;
}