#include <iostream>
using namespace std;
using ll = long long;

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
  ll t;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      ll east = A[people[i]];
      for (ll j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) >> 1;
          break;
        }
      }
      ll diff = abs(t - A[people[i]]);
      if (T < diff) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      ll west = A[people[i]];
      for (ll j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) >> 1;
          break;
        } else {
          west = A[j];
        }
      }
      ll diff = abs(A[people[i]] - t);
      if (T < diff) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }
  return 0;
}