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

  // Input
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }

  // Process queries
  for (int i = 0; i < Q; i++) {
    ll t = A[people[i]]; // Initialize t with the current person's position

    if (D[people[i]] == 1) {
      // East direction
      for (ll j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          t = A[j]; // Update t with the latest east position
        } else {
          t = (t + A[j]) / 2; // Calculate the midpoint
          break;
        }
      }

      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      // West direction
      for (ll j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (t + A[j]) / 2; // Calculate the midpoint
          break;
        } else {
          t = A[j]; // Update t with the latest west position
        }
      }

      if (T < abs(A[people[i]] - t)) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }

  return 0;
}