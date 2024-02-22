#include <iostream>
#include <limits.h>
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
  ll t_east, t_west;
  for (int i = 0; i < N; i++) {
    if (D[i] == 1) {
      east = A[i];
      if (i < N - 1 && D[i + 1] == 2) {
        t_east = (east + A[i + 1]) / 2;
      }
    } else {
      west = A[i];
      if (i > 0 && D[i - 1] == 1) {
        t_west = (west + A[i - 1]) / 2;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      if (T < abs(t_east - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t_east << endl;
      }
    } else {
      if (T < abs(A[people[i]] - t_west)) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t_west << endl;
      }
    }
  }
  return 0;
}