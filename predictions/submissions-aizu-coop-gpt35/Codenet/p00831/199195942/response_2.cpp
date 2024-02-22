#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memset

const int MAX_N = 1000;
const int MAX_LENGTH = 50;

int damerau_levenshtein_distance(const char* a, const char* b, int alphabet_size) {
  int d[MAX_LENGTH + 1][MAX_LENGTH + 1];
  int maxdist = strlen(a) + strlen(b);

  for (int i = 0; i <= strlen(a); ++i) {
    d[i][0] = i;
  }

  for (int i = 0; i <= strlen(b); ++i) {
    d[0][i] = i;
  }

  for (int i = 1; i <= strlen(a); ++i) {
    int db = 0;
    for (int j = 1; j <= strlen(b); ++j) {
      int k = db, l = j - 1, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else {
        cost = 1;
      }
      d[i][j] = std::min({ d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                           d[k][l] + (i - k - 1) + 1 + (j - l - 1) });
    }
  }

  return d[strlen(a)][strlen(b)];
}

void solve(int n) {
  int d;
  char name[MAX_N][MAX_LENGTH];
  std::cin >> d;

  for (int i = 0; i < n; ++i) {
    std::cin >> name[i];
  }

  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (damerau_levenshtein_distance(name[i], name[j], 26) > d) {
        continue;
      }
      ++count;
      std::cout << name[i] << "," << name[j] << std::endl;
    }
  }

  std::cout << count << std::endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);

  while (true) {
    int n;
    std::cin >> n;

    if (n == 0) {
      break;
    }

    solve(n);
  }

  return 0;
}