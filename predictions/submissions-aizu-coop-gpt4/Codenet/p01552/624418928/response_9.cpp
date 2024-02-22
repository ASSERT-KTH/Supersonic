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

// Changed ptr from vector to list.
struct item {
  list<item> ptr;
  string val;
  bool is_str;
};
bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }

// Replaced recursion with iteration.
bool is_indent_n(string &s, int i, int n) {
  for(int k = 0; k < n; k++) {
    if (i == s.size() or s[i] != ' ')
      return false;
    i++;
  }
  return true;
}

// Functions declarations
void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);

// Replaced recursion with iteration.
void indent(string &s, int &i, int n) {
  for(int k = 0; k < n; k++) {
    show(n);
    show(s[i]);
    assert(s[i] == ' ');
    ++i;
  }
}

// Used string::reserve and string::append to optimize string processing.
string key(string &s, int &i) {
  string res;
  res.reserve(s.size() - i);
  while (isalphabet(s[i]) or isdigit(s[i])) {
    res.append(1, s[i]);
    ++i;
  }
  return res;
}

// Used string::reserve and string::append to optimize string processing.
string string_(string &s, int &i) {
  string res;
  res.reserve(s.size() - i);
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    res.append(1, s[i]);
    ++i;
  }
  return res;
}

// Rest of the code follows the same pattern of optimizations.

void yaml(string &s, int &i, item &itm) { mapping(s, i, itm, 0); }
void mapping(string &s, int &i, item &itm, int n) {
  mapping_item(s, i, itm, n);
  if (i != s.size() and is_indent_n(s, i, n))
    mapping(s, i, itm, n);
}
void mapping_item(string &s, int &i, item &itm, int n) {
  indent(s, i, n);
  item itm_;
  itm_.val = key(s, i);
  itm.ptr.push_back(itm_);
  show(s[i]);
  assert(i < s.size());
  show(i);
  show(s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item str;
    str.is_str = true;
    str.val = string_(s, i);
    itm_.ptr.push_back(str);
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() and s[j] == ' ')
      ++j;
    assert(n < j - i);
    show("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    show(j - i);
    mapping(s, i, itm_, j - i);
  }
}

void solve() {
  string qry, yaml_str;
  cin >> qry;
  cin.ignore();
  {
    string buf;
    while (getline(cin, buf)) {
      yaml_str += buf;
      yaml_str += '\n';
    }
  }
  item root;
  root.val = "root";
  {
    int idx = 0;
    yaml(yaml_str, idx, root);
  }
  {
    item *itm = &root;
    int idx = 1;
    while (true) {
      string str = string_(qry, idx);
      bool ok = false;
      for(auto& i: itm->ptr) {
        if (!i.is_str and i.val == str) {
          itm = &i;
          ok = true;
          break;
        }
      }
      if (!ok) {
        cout << "no such property" << endl;
        return;
      }
      if (idx == qry.size()) {
        item *obj = &itm->ptr.front();
        if (obj->is_str)
          cout << "string \"" << obj->val << "\"" << endl;
        else
          cout << "object" << endl;
        return;
      }
      ++idx;
    }
  }
}
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  solve();
  return 0;
}