#include <stdio.h>
#include <vector>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);
int main() {
  int N, Q;
  ll T;
  scanf("%d %lld %d", &N, &T, &Q);
  vector<ll> A(N), D(N), people(Q), final_position(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &A[i], &D[i]);
  }
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &people[i]);
    people[i]--;
  }
  ll east = MIN, west = MIN, t;
  for (int i = 0; i < N; i++) {
    if (D[i] == 1) {
      east = A[i];
      if (i < N - 1 && D[i + 1] == -1) {
        t = (east + A[i + 1]) / 2;
        final_position[i] = min(A[i] + T, t);
      } else {
        final_position[i] = A[i] + T;
      }
    } else {
      west = A[i];
      if (i > 0 && D[i - 1] == 1) {
        t = (west + A[i - 1]) / 2;
        final_position[i] = max(A[i] - T, t);
      } else {
        final_position[i] = A[i] - T;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    printf("%lld\n", final_position[people[i]]);
  }
  return 0;
}