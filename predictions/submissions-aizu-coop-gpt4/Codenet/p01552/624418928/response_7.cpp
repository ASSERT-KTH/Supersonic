#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)
typedef long long int ll;
typedef pair<int, int> pii;
template <typename T> using vec = std::vector<T>;
const int inf = 1 << 30;
const long long int infll = 1LL << 62;

struct item {
  unordered_map<string, item> ptr;
  string val;
  bool is_str;
};

bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }
bool is_indent_n(const string &s, int i, int n) {
  if (n == 0)
    return true;
  if (i >= s.size() or s[i] != ' ')
    return false;
  return is_indent_n(s, i + 1, n - 1);
}

void yaml(const string &s, int &i, item &itm);
void mapping(const string &s, int &i, item &itm, int n);
void mapping_item(const string &s, int &i, item &itm, int n);
string key(const string &s, int &i);
string string_(const string &s, int &i);
void indent(const string &s, int &i, int n);

void yaml(const string &s, int &i, item &itm) { mapping(s, i, itm, 0); }
void mapping(const string &s, int &i, item &itm, int n) {
  while (i < s.size() && is_indent_n(s, i, n)) {
    mapping_item(s, i, itm, n);
  }
}
void mapping_item(const string &s, int &i, item &itm, int n) {
  indent(s, i, n);
  string key_str = key(s, i);
  assert(i < s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item str_item;
    str_item.is_str = true;
    str_item.val = string_(s, i);
    itm.ptr[key_str] = str_item;
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j < s.size() and s[j] == ' ')
      ++j;
    assert(n < j - i);
    mapping(s, i, itm.ptr[key_str], j - i);
  }
}
string key(const string &s, int &i) {
  stringstream res;
  while (i < s.size() && (isalphabet(s[i]) or isdigit(s[i]))) {
    res << s[i];
    ++i;
  }
  return res.str();
}
string string_(const string &s, int &i) {
  stringstream res;
  while (i < s.size() && (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ')) {
    res << s[i];
    ++i;
  }
  return res.str();
}
void indent(const string &s, int &i, int n) {
  while (n-- > 0) {
    assert(i < s.size() && s[i] == ' ');
    ++i;
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
      if (itm->ptr.count(str) == 0) {
        cout << "no such property" << endl;
        return;
      }
      itm = &itm->ptr[str];
      if (idx == qry.size()) {
        if (itm->is_str)
          cout << "string \"" << itm->val << "\"" << endl;
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