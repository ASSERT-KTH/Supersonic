#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  int N, Q;
  int T;
  cin >> N >> T >> Q;
  int* people = new int[Q];
  int* A = new int[N];
  int* D = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  int t;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      int east = A[people[i]];
      for (int j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < abs(t - A[people[i]])) {
        cout << A[people[i]] + T << endl;
      } else {
        cout << t << endl;
      }
    } else {
      int west = A[people[i]];
      for (int j = people[i] - 1; j >= 0; j--) {
        if (D[j] != 1) {
          west = A[j];
        } else {
          t = (west + A[j]) / 2;
          break;
        }
      }
      if (T < abs(A[people[i]] - t)) {
        cout << A[people[i]] - T << endl;
      } else {
        cout << t << endl;
      }
    }
  }
  delete[] people;
  delete[] A;
  delete[] D;
  return 0;
}