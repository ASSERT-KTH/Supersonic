#include <iostream>
#include <climits>
#include <vector>

int main() {
  int N, Q;
  long long T;
  std::cin >> N >> T >> Q;

  std::vector<long long> A(N);
  std::vector<int> D(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i] >> D[i];
  }

  std::vector<int> people(Q);
  for (int i = 0; i < Q; i++) {
    std::cin >> people[i];
    people[i]--;
  }

  long long east = INT_MIN;
  long long west = INT_MIN;
  long long t;

  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      for (int j = people[i] + 1; j < N; j++) {
        east = (D[j] == 1) ? A[j] : (t = (east + A[j]) / 2, break);
      }
      std::cout << ((T < t - A[people[i]]) ? A[people[i]] + T : t) << std::endl;
    } else {
      west = A[people[i]];
      for (int j = people[i] - 1; j >= 0; j--) {
        t = (D[j] == 1) ? (west + A[j]) / 2 : (west = A[j]);
        if (D[j] == 1) {
          break;
        }
      }
      std::cout << ((T < A[people[i]] - t) ? A[people[i]] - T : t) << std::endl;
    }
  }

  return 0;
}