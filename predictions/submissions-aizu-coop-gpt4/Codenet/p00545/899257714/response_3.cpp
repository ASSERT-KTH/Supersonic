#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  ll T;
  cin >> N >> T >> Q;

  vector<ll> people(Q);
  vector<ll> A(N);
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
    ll person = people[i];
    ll person_pos = A[person];
    int direction = D[person];

    if (direction == 1) {
      east = person_pos;
      
      for (ll j = person + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      
      if (T < abs(t - person_pos)) {
        cout << person_pos + T << '\n';
      } else {
        cout << t << '\n';
      }
    } else {
      west = person_pos;
      
      for (ll j = person - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      
      if (T < abs(person_pos - t)) {
        cout << person_pos - T << '\n';
      } else {
        cout << t << '\n';
      }
    }
  }
  
  return 0;
}