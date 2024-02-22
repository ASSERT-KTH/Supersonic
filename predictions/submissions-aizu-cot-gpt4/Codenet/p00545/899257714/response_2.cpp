#include <stdio.h>
#include <limits.h>
typedef long long ll;
const ll MIN = -(LONG_LONG_MAX - 1);
int main() {
  int N, Q;
  ll T;
  scanf("%d %lld %d", &N, &T, &Q);
  ll people[1001];
  ll A[100001];
  int D[100001];
  for (int i = 0; i < N; i++) {
    scanf("%lld %d", &A[i], &D[i]);
  }
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &people[i]);
    people[i]--;
  }
  ll t;
  for (int i = 0; i < Q; i++) {
    int p = people[i];
    if (D[p] == 1) {
      ll east = A[p];
      ll j = p + 1;
      while (j < N && D[j] == 1) {
        east = A[j];
        j++;
      }
      if (j < N) t = (east + A[j]) / 2;
      if (T < abs(t - A[p])) {
        printf("%lld\n", A[p] + T);
      } else {
        printf("%lld\n", t);
      }
    } else {
      ll west = A[p];
      ll j = p - 1;
      while (j >= 0 && D[j] == 0) {
        west = A[j];
        j--;
      }
      if (j >= 0) t = (west + A[j]) / 2;
      if (T < abs(A[p] - t)) {
        printf("%lld\n", A[p] - T);
      } else {
        printf("%lld\n", t);
      }
    }
  }
  return 0;
}