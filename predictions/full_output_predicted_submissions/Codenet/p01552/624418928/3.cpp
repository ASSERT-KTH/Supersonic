#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)
#define debug(x) #x << "=" << (x)
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif
typedef long long int ll;
typedef pair<int, int> pii;
template <typename T> using vec = std::vector<T>;
const int inf = 1 << 30;
const long long int infll = 1LL << 62;
const double eps = 1e-9;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}
struct item {
  vector<item *> ptr;
  string val;
  bool is_str;
};
bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }
inline bool is_indent_n(string &s, int i, int n) {
  if (n == 0)
    return true;
  if (i == s.size() or s[i] != ' ')
    return false;
  return is_indent_n(s, i + 1, n - 1);
}
void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s,