#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cassert>
#include <algorithm>
using namespace std;
#define rep(i, x, y) for (int i = (x); i < (y); ++i)

struct item {
  vector<unique_ptr<item>> ptr;
  string val;
  bool is_str;
};

inline bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }
inline bool is_indent_n(const string &s, int i, int n) {
  return (n == 0) || ((i != s.size() && s[i] == ' ') && is_indent_n(s, i + 1, n - 1));
}

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);

void yaml(string &s, int &i, item &itm) { mapping(s, i, itm, 0); }
void mapping(string &s, int &i, item &itm, int n) {
  mapping_item(s, i, itm, n);
  if (i != s.size() and is_indent_n(s, i, n))
    mapping(s, i, itm, n);
}

void mapping_item(string &s, int &i, item &itm, int n) {
  indent(s, i, n);
  auto itm_ = make_unique<item>();
  itm_->val = key(s, i);
  itm.ptr.push_back(move(itm_));
  assert(i < s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    auto str = make_unique<item>();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr.push_back(move(str));
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
  int start = i;
  while (isalphabet(s[i]) or isdigit(s[i])) {
    ++i;
  }
  return s.substr(start, i - start);
}

string string_(string &s, int &i) {
  int start = i;
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    ++i;
  }
  return s.substr(start, i - start);
}

void indent(string &s, int &i, int n) {
  if (n == 0)
    return;
  assert(s[i] == ' ');
  ++i;
  indent(s, i, n - 1);
}

void solve() {
  string qry, yaml_str;
  cin >> qry;
  cin.ignore();
  yaml_str.assign((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());

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
      rep(i, 0, itm->ptr.size()) if (!itm->ptr[i]->is_str and
                                     itm->ptr[i]->val == str) {
        itm = itm->ptr[i].get();
        ok = true;
        break;
      }
      if (!ok) {
        cout << "no such property" << endl;
        return;
      }
      if (idx == qry.size()) {
        item *obj = itm->ptr.front().get();
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
  std::ios::sync_with_stdio(false);
  cout.precision(10);
  solve();
  return 0;
}