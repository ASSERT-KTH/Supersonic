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
  list<item *> ptr;
  string val;
  bool is_str;
};
bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }
bool is_indent_n(string &s, int i, int n) {
  for(int j=0; j<n; j++, i++){
    if(i==s.size()||s[i]!=' ')
        return false;
  }
  return true;
}
void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);
void yaml(string &s, int &i, item &itm) { mapping(s, i, itm, 0); }
void mapping(string &s, int &i, item &itm, int n) {
  while(i!=s.size()&&is_indent_n(s,i,n)){
    mapping_item(s,i,itm,n);
  }
}
void mapping_item(string &s, int &i, item &itm, int n) {
  indent(s, i, n);
  item *itm_ = new item();
  itm_->val = key(s, i);
  itm.ptr.push_back(itm_);
  assert(i < s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item *str = new item();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr.push_back(str);
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() and s[j] == ' ')
      ++j;
    assert(n < j - i);
    mapping(s, i, *itm_, j - i);
  }
}
string key(string &s, int &i) {
  string res;
  res.reserve(100);
  while (isalphabet(s[i]) or isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}
string string_(string &s, int &i) {
  string res;
  res.reserve(100);
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}
void indent(string &s, int &i, int n) {
  for(int j=0; j<n; j++){
    assert(s[i] == ' ');
    ++i;
  }
}
void solve() {
  string qry, yaml_str;
  cin >> qry;
  cin.ignore();
  {
    string buf;
    stringstream ss;
    while (getline(cin, buf)) {
      ss << buf << '\n';
    }
    yaml_str = ss.str();
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
      for(auto i: itm->ptr){
        if (!i->is_str and i->val == str) {
          itm = i;
          ok = true;
          break;
        }
      }
      if (!ok) {
        cout << "no such property" << endl;
        return;
      }
      if (idx == qry.size()) {
        item *obj = itm->ptr.front();
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