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
  int prefix[100001];
  int suffix[100001];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
    if (i > 0 && D[i] == 1) {
      prefix[i] = i;
    } else {
      prefix[i] = prefix[i-1];
    }
  }
  suffix[N-1] = (D[N-1] == -1) ? N-1 : -1;
  for (int i = N-2; i >= 0; i--) {
    if (D[i] == -1) {
      suffix[i] = i;
    } else {
      suffix[i] = suffix[i+1];
    }
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
      int j = suffix[people[i]];
      if (j != -1) {
        t = (A[people[i]] + A[j]) / 2;
      }
      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      int j = prefix[people[i]];
      if (j != -1) {
        t = (A[people[i]] + A[j]) / 2;
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