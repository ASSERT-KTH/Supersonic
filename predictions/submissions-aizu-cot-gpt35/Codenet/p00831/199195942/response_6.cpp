#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

const int alphabet_size = 26;

int damerau_levenshtein_distance(const std::string &a, const std::string &b) {
  std::vector<int> da(alphabet_size, 0);
  std::vector<std::vector<int>> d(a.size() + 1, std::vector<int>(b.size() + 1, 0));
  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  for (int i = 1; i <= a.size(); ++i) {
    d[i][0] = i;
  }
  for (int i = 1; i <= b.size(); ++i) {
    d[0][i] = i;
  }
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1]], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else {
        cost = 1;
      }
      d[i][j] = std::min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                     d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]] = i;
  }
  return d[a.size()][b.size()];
}

struct NameComparator {
  bool operator()(const std::string& a, const std::string& b) {
    return a.size() < b.size();
  }
};

void solve(int n) {
  int d;
  std::vector<std::string> name(n);
  scanf("%d", &d);
  for (int i = 0; i < n; ++i) {
    std::cin >> name[i];
  }
  std::sort(name.begin(), name.end(), NameComparator());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (damerau_levenshtein_distance(name[i], name[j]) > d) {
        continue;
      }
      ++count;
      std::cout << name[i] << "," << name[j] << std::endl;
    }
  }
  printf("%d\n", count);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);
  for (;;) {
    int n;
    scanf("%d", &n);
    if (!n) {
      break;
    }
    solve(n);
  }
  return 0;
}