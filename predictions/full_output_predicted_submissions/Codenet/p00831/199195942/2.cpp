#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)
#define debug(x) #x << "=" << (x)
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
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
int damerau_levenshtein_distance(const string &a, const string &b,
                                 const int alphabet_size) {
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
      int k =