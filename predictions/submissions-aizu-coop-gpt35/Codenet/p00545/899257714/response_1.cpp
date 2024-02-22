#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  vector<ll> people(Q);
  vector<ll> A(N);
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  ll east = INT_MIN;
  ll west = INT_MIN;
  ll t;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      int j = people[i] + 1;
      while (j < N && D[j] != 1) {
        east = A[j];
        j++;
      }
      if (j < N) {
        t = (east + A[j]) / 2;
      } else {
        t = east;
      }
      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      west = A[people[i]];
      int j = people[i] - 1;
      while (j >= 0 && D[j] != 1) {
        west = A[j];
        j--;
      }
      if (j >= 0) {
        t = (west + A[j]) / 2;
      } else {
        t = west;
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