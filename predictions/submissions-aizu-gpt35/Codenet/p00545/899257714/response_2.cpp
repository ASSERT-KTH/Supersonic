#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
using ll = long long;

const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;

  ll A[100001];
  int D[100001];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }

  sort(A, A + N);

  ll people[1001];
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }

  for (int i = 0; i < Q; i++) {
    ll t;
    if (D[people[i]] == 1) {
      int idx = upper_bound(A, A + N, A[people[i]]) - A;
      if (idx < N && D[idx] == 2) {
        t = (A[people[i]] + A[idx]) / 2;
      } else {
        t = A[people[i]] + T;
      }
    } else {
      int idx = lower_bound(A, A + N, A[people[i]]) - A - 1;
      if (idx >= 0 && D[idx] == 1) {
        t = (A[people[i]] + A[idx]) / 2;
      } else {
        t = A[people[i]] - T;
      }
    }
    cout << t << endl;
  }
  return 0;
}