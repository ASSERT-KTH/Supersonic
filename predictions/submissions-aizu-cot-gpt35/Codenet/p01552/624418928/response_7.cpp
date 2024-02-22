#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct item {
  vector<item&> ptr;
  string val;
  bool is_str;
};

bool isalphabet(char ch) {
  return 'a' <= ch and ch <= 'z';
}

bool is_indent_n(string& s, int i, int n) {
  for (; n > 0; --n) {
    if (i == s.size() || s[i] != ' ')
      return false;
    ++i;
  }
  return true;
}

void yaml(string& s, int& i, item& itm);
void mapping(string& s, int& i, item& itm, int n);
void mapping_item(string& s, int& i, item& itm, int n);
string key(string& s, int& i);
string string_(string& s, int& i);
void indent(string& s, int& i, int n);

void yaml(string& s, int& i, item& itm) {
  mapping(s, i, itm, 0);
}

void mapping(string& s, int& i, item& itm, int n) {
  while (true) {
    mapping_item(s, i, itm, n);
    if (i == s.size() || !is_indent_n(s, i, n))
      break;
  }
}

void mapping_item(string& s, int& i, item& itm, int n) {
  indent(s, i, n);
  item& itm_ = itm.ptr.emplace_back();
  itm_.val = key(s, i);
  show(s[i]);
  assert(i < s.size());
  show(i);
  show(s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item& str = itm_.ptr.emplace_back();
    str.is_str = true;
    str.val = string_(s, i);
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() && s[j] == ' ')
      ++j;
    assert(n < j - i);
    mapping(s, i, itm_, j - i);
  }
}

string key(string& s, int& i) {
  string res;
  while (isalphabet(s[i]) || isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

string string_(string& s, int& i) {
  string res;
  while (isalphabet(s[i]) || isdigit(s[i]) || s[i] == ' ') {
    res += s[i];
    ++i;
  }
  return res;
}

void indent(string& s, int& i, int n) {
  while (n > 0) {
    assert(s[i] == ' ');
    ++i;
    --n;
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
    item& itm = root;
    int idx = 1;
    while (true) {
      string str = string_(qry, idx);
      bool ok = false;
      for (auto& ptr : itm.ptr) {
        if (!ptr.is_str && ptr.val == str) {
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
        item& obj = itm.ptr.front();
        if (obj.is_str)
          cout << "string \"" << obj.val << "\"" << endl;
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