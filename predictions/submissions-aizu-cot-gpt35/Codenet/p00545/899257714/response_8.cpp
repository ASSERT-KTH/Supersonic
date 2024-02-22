#include <iostream>
#include <vector>
#include <cmath>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int N, Q;
  long long T;
  std::cin >> N >> T >> Q;

  std::vector<long long> people(Q);
  std::vector<long long> A(N);
  std::vector<int> D(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i] >> D[i];
  }

  for (int i = 0; i < Q; i++) {
    std::cin >> people[i];
    people[i]--;
  }

  for (int i = 0; i < Q; i++) {
    bool isEast = (D[people[i]] == 1);
    long long east = A[people[i]];
    long long west = A[people[i]];
    long long t = A[people[i]];
    
    for (int j = people[i] + 1; j < N && j >= 0; isEast ? j++ : j--) {
      if (D[j] == 1) {
        if (isEast) {
          east = A[j];
        } else {
          t = (west + A[j]) / 2;
          break;
        }
      } else {
        if (isEast) {
          t = (east + A[j]) / 2;
          break;
        } else {
          west = A[j];
        }
      }
    }
    
    if (T < std::abs(t - A[people[i]])) {
      std::cout << (isEast ? A[people[i]] + T : A[people[i]] - T) << '\n';
    } else {
      std::cout << t << '\n';
    }
  }
  
  return 0;
}