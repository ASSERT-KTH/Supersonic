#include <iostream>

int main() {
  int N, Q;
  long long T;
  std::cin >> N >> T >> Q;
  long long* A = new long long[N];
  int* D = new int[N];
  for (int i = 0; i < N; i++) {
    std::cin >> A[i] >> D[i];
  }
  long long* people = new long long[Q];
  for (int i = 0; i < Q; i++) {
    std::cin >> people[i];
    people[i]--;
  }
  long long east = A[people[0]];
  long long west = A[people[0]];
  long long t = 0;
  for (int i = 0; i < Q; i++) {
    if (D[people[i]] == 1) {
      east = A[people[i]];
      for (long long j = people[i] + 1; j < N; j++) {
        if (D[j] == 1) {
          east = A[j];
        } else {
          t = (east + A[j]) / 2;
          break;
        }
      }
      if (T < t - A[people[i]]) {
        std::cout << A[people[i]] + T << std::endl;
      } else {
        std::cout << t << std::endl;
      }
    } else {
      west = A[people[i]];
      for (long long j = people[i] - 1; j >= 0; j--) {
        if (D[j] == 1) {
          t = (west + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
      if (T < A[people[i]] - t) {
        std::cout << A[people[i]] - T << std::endl;
      } else {
        std::cout << t << std::endl;
      }
    }
  }
  delete[] A;
  delete[] D;
  delete[] people;
  return 0;
}