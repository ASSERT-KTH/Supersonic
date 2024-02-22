#include <iostream>
#include <vector>
using namespace std;

struct item {
  vector<item *> ptr;
  string val;
  bool is_str;
};

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);

bool is_indent_n(string &s, int i, int n) {
  if (n == 0)
    return true;
  if (i == s.size() or s[i] != ' ')
    return false;
  return is_indent_n(s, i + 1, n - 1);
}

void yaml(string &s, int &i, item &itm) {
  mapping(s, i, itm, 0);
}

void mapping(string &s, int &i, item &itm, int n) {
  mapping_item(s, i, itm, n);
  while (i != s.size() and is_indent_n(s, i, n))
    mapping_item(s, i, itm, n);
}

void mapping_item(string &s, int &i, item &itm, int n) {
  indent(s, i, n);
  item *itm_ = new item();
  itm_->val = key(s, i);
  itm.ptr.push_back(itm_);

  ++i;
  if (s[i] == ' ') {
    ++i;
    item *str = new item();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr.push_back(str);
    ++i;
  } else {
    ++i;
    int j = i;
    while (j != s.size() and s[j] == ' ')
      ++j;
    mapping(s, i, *itm_, j - i);
  }
}

string key(string &s, int &i) {
  string res;
  while (isalpha(s[i]) or isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

string string_(string &s, int &i) {
  string res;
  while (isalpha(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}

void indent(string &s, int &i, int n) {
  if (n == 0)
    return;
  ++i;
  indent(s, i, n - 1);
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
      for (item *ptr : itm->ptr) {
        if (!ptr->is_str and ptr->val == str) {
          itm = ptr;
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