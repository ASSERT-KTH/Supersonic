#include <iostream>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
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
      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      west = A[people[i]];
      for (ll j = people[i] - 1; j >= 0; j--