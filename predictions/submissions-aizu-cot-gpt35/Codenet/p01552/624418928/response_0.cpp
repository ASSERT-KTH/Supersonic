#include <iostream>
#include <sstream>
#include <vector>

struct item {
  std::vector<item&> ptr;
  std::string val;
  bool is_str;
};

bool isalphabet(char ch) {
  return 'a' <= ch and ch <= 'z';
}

bool is_indent_n(const std::string& s, int i, int n) {
  if (n == 0)
    return true;
  if (i == s.size() or s[i] != ' ')
    return false;
  while (n > 0) {
    if (i == s.size() or s[i] != ' ')
      return false;
    ++i;
    --n;
  }
  return true;
}

void yaml(const std::string& s, int& i, item& itm);
void mapping(const std::string& s, int& i, item& itm, int n);
void mapping_item(const std::string& s, int& i, item& itm, int n);
std::string key(const std::string& s, int& i);
std::string string_(const std::string& s, int& i);
void indent(const std::string& s, int& i, int n);

void yaml(const std::string& s, int& i, item& itm) {
  mapping(s, i, itm, 0);
}

void mapping(const std::string& s, int& i, item& itm, int n) {
  mapping_item(s, i, itm, n);
  while (i != s.size() && is_indent_n(s, i, n))
    mapping(s, i, itm, n);
}

void mapping_item(const std::string& s, int& i, item& itm, int n) {
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
    while (j != s.size() and s[j] == ' ')
      ++j;
    assert(n < j - i);
    show("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    show(j - i);
    mapping(s, i, itm_, j - i);
  }
}

std::string key(const std::string& s, int& i) {
  std::string res;
  while (isalphabet(s[i]) or isdigit(s[i])) {
    res += s[i];
    ++i;
  }
  return res;
}

std::string string_(const std::string& s, int& i) {
  int start = i;
  while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
    ++i;
  }
  return s.substr(start, i - start);
}

void indent(const std::string& s, int& i, int n) {
  while (n > 0) {
    assert(s[i] == ' ');
    ++i;
    --n;
  }
}

void solve() {
  std::string qry, yaml_str;
  std::cin >> qry;
  std::cin.ignore();
  
  {
    std::string buf;
    while (std::getline(std::cin, buf)) {
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
      std::string str = string_(qry, idx);
      bool ok = false;
      for (item* sub_itm : itm.ptr) {
        if (!sub_itm->is_str && sub_itm->val == str) {
          itm = *sub_itm;
          ok = true;
          break;
        }
      }
      if (!ok) {
        std::cout << "no such property" << std::endl;
        return;
      }
      if (idx == qry.size()) {
        item* obj = itm.ptr.front();
        if (obj->is_str)
          std::cout << "string \"" << obj->val << "\"" << std::endl;
        else
          std::cout << "object" << std::endl;
        return;
      }
      ++idx;
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  solve();
  
  return 0;
}