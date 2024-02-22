#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  size_t N, Q;
  int T;
  cin >> N >> T >> Q;
  int people[1001];
  int A[100001];
  int D[100001];
  for (size_t i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }
  for (size_t i = 0; i < Q; i++) {
    cin >> people[i];
    people[i]--;
  }
  int east, west, t;
  for (size_t i = 0; i < Q; i++) {
    east = A[people[i]]; // Initialize east with the initial value
    west = A[people[i]]; // Initialize west with the initial value
    size_t j = people[i];
    while (true) {
      if (D[j] == 1) { // Change direction to east
        t = (east + A[j]) >> 1;
        break;
      } else if (j == 0) {
        break;
      } else { // Continue in the same direction
        east = A[j];
        j--;
      }
    }
    if (T < ((t > A[people[i]]) ? (t - A[people[i]]) : (A[people[i]] - t))) { // Avoid unnecessary absolute value calculation
      cout << A[people[i]] + T << endl;
    } else {
      cout << t << endl;
    }
  }
  return 0;
}