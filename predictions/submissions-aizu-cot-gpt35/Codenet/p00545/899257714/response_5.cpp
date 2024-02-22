#include <iostream>
using namespace std;

int main() {
  int N, Q, T;
  cin >> N >> T >> Q;
  
  int* people = new int[Q];
  int* A = new int[N];
  int* D = new int[N];
  
  for (int i = 0; i < N && i < 100001; i++) {
    cin >> A[i] >> D[i];
  }
  
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  
  int east = INT_MIN;
  int west = INT_MIN;
  int t;
  
  int* results = new int[Q];
  
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      for (int j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      int diff = abs(t - A[people[i]]);
      results[i] = (T < diff) ? (A[people[i]] + T) : t;
    } else {
      west = A[people[i]];
      for (int j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      int diff = abs(A[people[i]] - t);
      results[i] = (T < diff) ? (A[people[i]] - T) : t;
    }
  }
  
  for (int i = 0; i < Q; i++) {
    cout << results[i] << endl;
  }
  
  delete[] people;
  delete[] A;
  delete[] D;
  delete[] results;
  
  return 0;
}