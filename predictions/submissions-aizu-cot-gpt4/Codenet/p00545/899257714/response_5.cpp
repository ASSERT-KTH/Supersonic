#include <cstdio>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);
int main() {
  int N, Q;
  ll T;
  scanf("%d%lld%d", &N, &T, &Q);
  ll people[N];
  ll A[N];
  int D[N];
  for (int i = 0; i < N; i++) {
    scanf("%lld%d", &A[i], &D[i]);
  }
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &people[i]);
    people[i]--;
  }
  ll east = MIN;
  ll west = MIN;
  ll t;
  for (int i = 0; i < Q; i++) {
    ll people_i = people[i];
    if (D[people_i] == 1) {
      east = A[people_i];
      for (ll j = people_i + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < abs(t - A[people_i])) {
        printf("%lld\n", A[people_i] + T);
      } else {
        printf("%lld\n", t);
      }
    } else {
      west = A[people_i];
      for (ll j = people_i - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      if (T < abs(A[people_i] - t)) {
        printf("%lld\n", A[people_i] - T);
      } else {
        printf("%lld\n", t);
      }
    }
  }
  return 0;
}