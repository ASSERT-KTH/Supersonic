#include <iostream>
#include <limits.h>
#include <sstream>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);
int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  ll people[1001];
  ll A[100001];
  int D[100001];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  ll east = MIN;
  ll west = MIN;
  stringstream ss;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      for (ll j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          if (T < abs((east + A[j]) / 2 - A[people[i]])) {
            ss << A[people[i]] + T << endl;
          } else {
            ss << (east + A[j]) / 2 << endl;
          }
          break;
        }
      }
    } else {
      west = A[people[i]];
      for (ll j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          if (T < abs(A[people[i]] - (west + A[j]) / 2)) {
            ss << A[people[i]] - T << endl;
          } else {
            ss << (west + A[j]) / 2 << endl;
          }
          break;
        } else {
          west = A[j];
        }
      }
    }
  }
  cout << ss.str();
  return 0;
}