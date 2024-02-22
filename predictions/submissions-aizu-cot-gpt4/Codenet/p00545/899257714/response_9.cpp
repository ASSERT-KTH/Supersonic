#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  
  vector<ll> A(N);
  vector<int> D(N);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  
  sort(A.begin(), A.end());
  sort(D.begin(), D.end());

  ll east = MIN;
  ll west = MIN;
  ll t;
  
  for (int i = 0; i < Q; i++) {
    int person;
    cin >> person;
    person--;
    
    if (D[person] == 1) {
      auto it = upper_bound(A.begin(), A.end(), A[person]);
      if (it != A.end()){
        east = *it;
        t = (east + A[person]) / 2;
      } else {
        t = A[person];
      }
      if (T < abs(t - A[person])) {
        cout << A[person] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      auto it = lower_bound(A.begin(), A.end(), A[person]);
      if (it != A.begin()){
        west = *(--it);
        t = (west + A[person]) / 2;
      } else {
        t = A[person];
      }
      if (T < abs(A[person] - t)) {
        cout << A[person] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }
  return 0;
}