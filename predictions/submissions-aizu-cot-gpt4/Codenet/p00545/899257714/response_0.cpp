#include <iostream>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
    --people[i];
  }
  ll east = MIN;
  ll west = MIN;
  ll t;
  for (int i = 0; i < Q; i++) {
    ll current_person = A[people[i]];
    if (D[people[i]] == 1) {
      east = current_person;
      for (ll j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < abs(t - current_person)) {
        cout << current_person + T << "\n";
      } else {
        cout << t << "\n";
      }
    } else {
      west = current_person;
      for (ll j = people[i] - 1; j >= 0; --j) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      if (T < abs(current_person - t)) {
        cout << current_person - T << "\n";
      } else {
        cout << t << "\n";
      }
    }
  }
  return 0;
}