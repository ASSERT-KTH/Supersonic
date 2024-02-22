#include <iostream>
#include <limits.h>
using namespace std;
using ll = long long;

const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  ll A[100001], final_pos[100001];
  int D[100001];

  // Input positions and directions
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> D[i];
  }

  ll east = MIN, west = MIN;
  // Calculate final positions, 'east' and 'west' in a single pass
  for (int i = 0; i < N; i++) {
    if (D[i] == 1) {
      east = A[i];
      if (i > 0 && D[i-1] == -1) {
        east = (A[i-1] + A[i]) / 2;
      }
      final_pos[i] = min(A[i] + T, east);
    } else {
      west = A[i];
      if (i < N-1 && D[i+1] == 1) {
        west = (A[i] + A[i+1]) / 2;
      }
      final_pos[i] = max(A[i] - T, west);
    }
  }

  // Process queries
  int query;
  for (int i = 0; i < Q; i++) {
    cin >> query;
    query--;
    cout << final_pos[query] << endl;
  }

  return 0;
}