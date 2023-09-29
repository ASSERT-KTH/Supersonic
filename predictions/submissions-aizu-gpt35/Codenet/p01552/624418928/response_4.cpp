#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct item {
  unordered_map<string, item *> ptr;
  string val;
  bool is_str;
};

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm);
void mapping_item(string &s, int &i, item &itm);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);

void yaml(string &s, int &i, item &itm) { mapping(s, i, itm); }

void mapping(string &s, int &i, item &itm) {
  mapping_item(s, i, itm);
  if (i != s.size() and s[i] == '\n')
    mapping(s, i, itm);
}

void mapping_item(string &s, int &i, item &itm) {
  indent(s, i, 0);
  item *itm_ = new item();
  itm_->val = key(s, i);
  itm->ptr[itm_->val] = itm_;
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item *str = new item();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr["value"] = str;
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() and s[j] == ' ')
      ++j;
    mapping(s, i, *itm_);
  }
}

string key(string &s, int &i) {
  string res;
  while ('a' <= s[i] and s[i] <= 'z' or isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

string string_(string &s, int &i) {
  string res;
  while ('a' <= s[i] and s[i] <= 'z' or isdigit(s[i]) or s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}

void indent(string &s, int &i, int n) {
  while (n-- > 0) {
    assert(s[i] == ' ');
    ++i;
  }
}

void solve() {
  string qry, yaml_str;
  getline(cin, qry);
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
  item *itm = &root;
  stringstream ss(qry);
  string str;
  while (getline(ss, str, '.')) {
    if (itm->ptr.find(str) == itm->ptr.end()) {
      cout << "no such property" << endl;
      return;
    }
    itm = itm->ptr[str];
  }
  if (itm->is_str)
    cout << "string \"" << itm->val << "\"" << endl;
  else
    cout << "object" << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  solve();
  return 0;
}