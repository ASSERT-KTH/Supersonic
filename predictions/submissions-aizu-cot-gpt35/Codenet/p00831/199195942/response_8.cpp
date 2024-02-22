#include <iostream>
#include <vector>
#include <algorithm>

const int alphabet_size = 26;

int damerau_levenshtein_distance(const std::string& a, const std::string& b) {
  std::vector<int> da(alphabet_size, -1);
  std::vector<std::vector<int>> d(a.size() + 1, std::vector<int>(b.size() + 1));
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
      int k = da[b[j - 1]], l = db, cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
      d[i][j] = std::min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                          d[k][l] + (i - k - 1) + 1 + (j - l - 1)});
      if (a[i - 1] == b[j - 1]) {
        db = j;
      }
    }
    da[a[i - 1]] = i;
  }
  return d[a.size()][b.size()];
}

void solve(int n) {
  int d;
  std::cin >> d;
  std::vector<std::string> name;
  name.reserve(n);
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    name.push_back(std::move(s));
  }
  std::stable_sort(name.begin(), name.end());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (damerau_levenshtein_distance(name[i], name[j]) <= d) {
        ++count;
      }
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
    if (!n) {
      break;
    }
    solve(n);
  }
  return 0;
}