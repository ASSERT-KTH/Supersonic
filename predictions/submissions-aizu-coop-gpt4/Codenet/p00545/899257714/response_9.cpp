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
  scanf("%d %lld %d", &N, &T, &Q);
  
  vector<ll> people(Q);
  vector<ll> A(N);
  vector<int> D(N);

  for (auto &i : A) {
    cin >> i;
  }
  for (auto &i : D) {
    cin >> i;
  }
  for (auto &i : people) {
    cin >> i;
    i--;
  }

  ll east = MIN;
  ll west = MIN;
  ll t;
  for (auto &i : people) {
    if (D[i] == 1) {
      east = A[i];
      for (ll j = i + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < abs(t - A[i])) {
        printf("%lld\n", A[i] + T);
      } else {
        printf("%lld\n", t);
      }
    } else {
      west = A[i];
      for (ll j = i - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      if (T < abs(A[i] - t)) {
        printf("%lld\n", A[i] - T);
      } else {
        printf("%lld\n", t);
      }
    }
  }
  return 0;
}