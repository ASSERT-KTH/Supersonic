#include <iostream>
#include <vector>
#include <algorithm>

int damerau_levenshtein_distance(const std::string& a, const std::string& b, const int alphabet_size) {
  int da[26] = {0};
  int d[a.size()+1][b.size()+1];

  int maxdist = a.size() + b.size();
  d[-1][-1] = maxdist;

  for (int i = 0; i <= a.size(); ++i) {
    d[i][-1] = maxdist;
    d[i][0] = i;
  }

  for (int i = 0; i <= b.size(); ++i) {
    d[-1][i] = maxdist;
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
      d[i][j] = d[i - 1][j - 1] + cost;
      if (d[i][j - 1] + 1 < d[i][j]) {
        d[i][j] = d[i][j - 1] + 1;
      }
      if (d[i - 1][j] + 1 < d[i][j]) {
        d[i][j] = d[i - 1][j] + 1;
      }
      if (d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1) < d[i][j]) {
        d[i][j] = d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1);
      }
    }
    da[a[i - 1] - 'a'] = i;
  }

  return d[a.size()][b.size()];
}

void solve(int n) {
  int d;
  std::vector<std::string> name(n);
  std::cin >> d;
  for (int i = 0; i < n; ++i) {
    std::cin >> name[i];
  }
  std::sort(name.begin(), name.end());

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (name[j].size() - name[i].size() > d) {
        break;
      }
      if (name[i][0] != name[j][0]) {
        continue;
      }
      if (damerau_levenshtein_distance(name[i], name[j], 26) <= d) {
        ++count;
        std::cout << name[i] << "," << name[j] << std::endl;
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

  for (;;) {
    int n;
    std::cin >> n;
    if (!n) {
      break;
    }
    solve(n);
  }

  return 0;
}