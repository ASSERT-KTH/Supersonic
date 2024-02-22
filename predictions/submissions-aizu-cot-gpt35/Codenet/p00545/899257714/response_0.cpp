#include <iostream>
using ll = long long;

int main() {
  int N, Q;
  ll T;
  std::cin >> N >> T >> Q;
  
  ll A[N];
  int D[N];
  for (int i = 0; i < N; i++) {
    std::cin >> A[i] >> D[i];
  }
  
  int people[Q];
  for (int i = 0; i < Q; i++) {
    std::cin >> people[i];
    people[i]--;
  }
  
  ll east, west, t, diff1, diff2;
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
      diff1 = t - A[people[i]];
      if (T < diff1) {
        std::cout << A[people[i]] + T << std::endl;
      } else {
        std::cout << t << std::endl;
      }
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
      diff2 = A[people[i]] - t;
      if (T < diff2) {
        std::cout << A[people[i]] - T << std::endl;
      } else {
        std::cout << t << std::endl;
      }
    }
  }
  
  return 0;
}