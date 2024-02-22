#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
  int to, c;
};

void maxUpdate(int &a, int b) { a = std::max(a, b); }

void mul(std::vector<std::vector<int>> &res, std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b) {
  int N = a.size();
  res = a;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (a[i][k] >= 0 && b[k][j] >= 0)
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
}

// ... rest of the program remains same