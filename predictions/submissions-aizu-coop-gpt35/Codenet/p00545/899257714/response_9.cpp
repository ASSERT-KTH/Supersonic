#include <iostream>
#include <limits.h>
using std::cin;
using std::cout;
using std::endl;

using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;

  ll* people = new ll[Q];
  ll* A = new ll[N];
  int* D = new int[N];

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
  ll abs_diff;

  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      ll max_east = east;

      for (ll j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
          max_east = east > max_east ? east : max_east;
        } else {
          t = (max_east + A[j]) / 2;
          break;
        }
      }

      abs_diff = abs(t - A[people[i]]);
      if (T < abs_diff) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      west = A[people[i]];
      for (ll j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }

      abs_diff = abs(A[people[i]] - t);
      if (T < abs_diff) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }

  delete[] people;
  delete[] A;
  delete[] D;

  return 0;
}