#include <iostream>
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
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  
  ll t;
  for (int i = 0; i < Q; i++) {
    ll east = MIN;
    ll west = MIN;
    
    if (D[people[i]] == 1) {
      east = A[people[i]];
      for (ll j = people[i] + 1; j < N && D[j] != 1; j++) {
        east = A[j];
      }
      t = (east + A[people[i]]) / 2;
      ll diff = t - A[people[i]];
      
      if (T < diff) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      west = A[people[i]];
      for (ll j = people[i] - 1; j >= 0 && D[j] != 1; j--) {
        west = A[j];
      }
      t = (west + A[people[i]]) / 2;
      ll diff = A[people[i]] - t;
      
      if (T < diff) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }
  
  return 0;
}