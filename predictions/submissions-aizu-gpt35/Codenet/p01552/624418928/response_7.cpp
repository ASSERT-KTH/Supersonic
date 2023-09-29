#include <bits/stdc++.h>
using namespace std;

struct item {
  map<string, item*> children;
  string val;
  bool is_str;
};

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm);
void mapping_item(string &s, int &i, item &itm);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);
void solve();

void yaml(string &s, int &i, item &itm) { mapping(s, i, itm); }

void mapping(string &s, int &i, item &itm) {
  mapping_item(s, i, itm);
  while (i != s.size() && s[i] == '\n') {
    ++i;
    int j = i;
    while (j != s.size() && s[j] == ' ') ++j;
    if (j - i > 0) {
      mapping(s, i, *itm.children[key(s, i)] = new item);
    }
  }
}

void mapping_item(string &s, int &i, item &itm) {
  indent(s, i, (int)itm.children.size());
  itm.val = key(s, i);
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    itm.is_str = true;
    itm.val = string_(s, i);
  }
}

string key(string &s, int &i) {
  string res;
  while (isalpha(s[i]) || isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

string string_(string &s, int &i) {
  string res;
  while (isalpha(s[i]) || isdigit(s[i]) || s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}

void indent(string &s, int &i, int n) {
  for (int j = 0; j < n; ++j) {
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
    while (getline(cin, buf)) {
      yaml_str += buf;
      yaml_str += '\n';
    }
  }
  item root;
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
      if (itm->children.count(str)) {
        itm = itm->children[str];
        ok = true;
      }
      if (!ok) {
        cout << "no such property" << endl;
        return;
      }
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