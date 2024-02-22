
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}

int damerau_levenshtein_distance(const string &a, const string &b) {
  unordered_map<int, int> da;
  unordered_map<int, unordered_map<int, int>> d;
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
      } else
        cost = 1;
      d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                     d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]] = i;
  }
  return d[a.size()][b.size()];
}

void solve(int n) {
  int d;
  vector<string> name;
  name.reserve(n);
  cin >> d;
  for(int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    name.push_back(temp);
  }
  sort(name.begin(), name.end());
  int count = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if (damerau_levenshtein_distance(name[i], name[j]) > d)
        continue;
      ++count;
      cout << name[i] << "," << name[j] << endl;
    }
  }
  cout << count << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  for (;;) {
    int n;
    cin >> n;
    if (!n)
      break;
    solve(n);
  }
  return 0;
}