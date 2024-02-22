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
  ll eastPos[100001];
  ll westPos[100001];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
    if (i > 0 && D[i] == 1 && D[i - 1] == 2) {
      eastPos[i - 1] = westPos[i] = (A[i - 1] + A[i]) / 2;
    }
    if (D[i] == 1) {
      eastPos[i] = A[i];
    } else if (i > 0) {
      eastPos[i] = eastPos[i - 1];
    }
    if (D[i] == 2) {
      westPos[i] = A[i];
    } else if (i > 0) {
      westPos[i] = westPos[i - 1];
    }
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  ll t;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      t = eastPos[people[i]];
      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      t = westPos[people[i]];
      if (T < abs(A[people[i]] - t)) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }
  return 0;
}