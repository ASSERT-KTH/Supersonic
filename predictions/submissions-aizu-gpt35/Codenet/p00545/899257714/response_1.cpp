#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);
const int MAX_N = 1001, MAX_Q = 100001;
ll A[MAX_N], people[MAX_Q];
int D[MAX_N];
int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  sort(A, A + N);
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  ll east, west, t;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      int j = people[i] + 1;
      while (j < N && D[j] == 1) {
        east = A[j];
        j++;
      }
      if (j < N) {
        t = (east + A[j]) / 2;
      } else {
        t = east + T;
      }
      cout << min(A[people[i]] + T, t) << endl;
    } else {
      west = A[people[i]];
      int j = people[i] - 1;
      while (j >= 0 && D[j] == 2) {
        west = A[j];
        j--;
      }
      if (j >= 0) {
        t = (west + A[j]) / 2;
      } else {
        t = west - T;
      }
      cout << max(A[people[i]] - T, t) << endl;
    }
  }
  return 0;
}