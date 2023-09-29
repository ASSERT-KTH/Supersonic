#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;

  vector<ll> people(Q), A(N), D(N), pos(N, MIN), t(N, MIN);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }

  for (int i = 0; i < N; i++) {
    if (D[i] == -1) pos[i] = max(pos[i], A[i] - T);
    else {
      if (i > 0 && D[i - 1] == -1) pos[i] = max(pos[i], (A[i - 1] + A[i]) / 2);
      pos[i] = max(pos[i], A[i] + T);
    }
    if (i > 0) pos[i] = max(pos[i], pos[i - 1]);
  }

  for (int i = N - 1; i >= 0; i--) {
    if (D[i] == 1) t[i] = min(t[i], A[i] + T);
    else {
      if (i < N - 1 && D[i + 1] == 1) t[i] = min(t[i], (A[i] + A[i + 1]) / 2);
      t[i] = min(t[i], A[i] - T);
    }
    if (i < N - 1) t[i] = min(t[i], t[i + 1]);
  }

  for (int i = 0; i < Q; i++) {
    cout << min(max(pos[people[i]], A[people[i]] - T), A[people[i]] + T) << "\n";
  }

  return 0;
}