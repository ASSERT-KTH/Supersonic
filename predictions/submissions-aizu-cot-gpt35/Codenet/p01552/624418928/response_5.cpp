#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct item {
  vector<item *> ptr;
  string val;
  bool is_str;
};

bool is_indent_n(string &s, int i, int n) {
  for (int j = 0; j < n; j++) {
    if (i + j >= s.size() || s[i + j] != ' ') {
      return false;
    }
  }
  return true;
}

void indent(string &s, int &i, int n) {
  for (int j = 0; j < n; j++) {
    assert(s[i] == ' ');
    i++;
  }
}

string string_(string &s, int &i) {
  string res;
  while (i < s.size() && (isalnum(s[i]) || isspace(s[i]))) {
    res += s[i];
    i++;
  }
  return res;
}

void yaml(string &s, int &i, item &itm) {
  int n = 0;
  while (i < s.size() && is_indent_n(s, i, n)) {
    indent(s, i, n);
    item *itm_ = new item();
    itm_->val = string_(s, i);
    itm.ptr.push_back(itm_);
    assert(i < s.size());
    assert(s[i] == ':');
    i++;
    if (s[i] == ' ') {
      i++;
      item *str = new item();
      str->is_str = true;
      str->val = string_(s, i);
      itm_->ptr.push_back(str);
      assert(s[i] == '\n');
      i++;
    } else {
      assert(s[i] == '\n');
      i++;
      int j = i;
      while (j < s.size() && s[j] == ' ')
        j++;
      assert(n < j - i);
      yaml(s, i, *itm_);
    }
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
      for (int i = 0; i < itm->ptr.size(); i++) {
        if (!itm->ptr[i]->is_str && itm->ptr[i]->val == str) {
          itm = itm->ptr[i];
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
      idx++;
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