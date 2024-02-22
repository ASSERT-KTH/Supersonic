#include <iostream>
#include <vector>
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

  vector<ll> people(Q), A(N);
  vector<int> D(N);

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
      for (ll j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
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
    }

    if (T < abs((D[people[i]] == 1 ? east : west) - t)) {
      cout << A[people[i]] + (D[people[i]] == 1 ? T : -T) << "\n";
    } else {
      cout << t << "\n";
    }
  }

  return 0;
}