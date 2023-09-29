I have optimized your program for memory usage and running time. Please find the optimized code below. 

#include <bits/stdc++.h>
using namespace std;
struct item {
  unordered_map<string, item *> ptr;
  string val;
  bool is_str;
};

bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm);
void mapping_item(string &s, int &i, item &itm);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i);
void solve();

void yaml(string &s, int &i, item &itm) { mapping(s, i, itm); }

void mapping(string &s, int &i, item &itm) {
  mapping_item(s, i, itm);
  if (i != s.size()) mapping(s, i, itm);
}

void mapping_item(string &s, int &i, item &itm) {
  indent(s, i);
  item *itm_ = new item();
  itm_->val = key(s, i);
  itm->ptr[itm_->val] = itm_;
  assert(i < s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item *str = new item();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr[""] = str;
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() and s[j] == ' ') ++j;
    mapping(s, i, *itm_);
  }
}

string key(string &s, int &i) {
  string res;
  while (isalphabet(s[i]) or isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

string string_(string &s, int &i) {
  string res;
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}

void indent(string &s, int &i) {
  while (s[i] == ' ') ++i;
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
      if (itm->ptr.find(str) != itm->ptr.end() &&
          !itm->ptr[str]->is_str) {
        itm = itm->ptr[str];
        ok = true;
      }
      if (!ok) {
        cout << "no such property" << endl;
        return;
      }
      if (idx == qry.size()) {
        item *obj = itm->ptr[""];
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}