#include <iostream>
#include <vector>
#include <cassert>

struct item {
  std::vector<item*> ptr;
  std::string val;
  bool is_str;
};

bool isalphabet(char ch) { return 'a' <= ch && ch <= 'z'; }

bool is_indent_n(const std::string& s, int i, int n) {
  if (n == 0)
    return true;
  if (i == s.size() || s[i] != ' ')
    return false;
  return is_indent_n(s, i + 1, n - 1);
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
  while (i != s.size() && is_indent_n(s, i, n)) {
    mapping_item(s, i, itm, n);
  }
}

void mapping_item(const std::string& s, int& i, item& itm, int n) {
  indent(s, i, n);
  item* itm_ = new item();
  itm_->val = key(s, i);
  itm.ptr.push_back(itm_);
  assert(i < s.size());
  assert(s[i] == ':');
  ++i;
  if (s[i] == ' ') {
    ++i;
    item* str = new item();
    str->is_str = true;
    str->val = string_(s, i);
    itm_->ptr.push_back(str);
    assert(s[i] == '\n');
    ++i;
  } else {
    assert(s[i] == '\n');
    ++i;
    int j = i;
    while (j != s.size() && s[j] == ' ')
      ++j;
    assert(n < j - i);
    mapping(s, i, *itm_, j - i);
  }
}

std::string key(const std::string& s, int& i) {
  std::string res;
  while (isalphabet(s[i]) || isdigit(s[i])) {
    res.push_back(s[i]);
    ++i;
  }
  return res;
}

std::string string_(const std::string& s, int& i) {
  std::string res;
  while (isalphabet(s[i]) || isdigit(s[i]) || s[i] == ' ') {
    res.push_back(s[i]);
    ++i;
  }
  return res;
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
      yaml_str.push_back('\n');
    }
  }
  item root;
  root.val = "root";
  {
    int idx = 0;
    yaml(yaml_str, idx, root);
  }
  {
    item* itm = &root;
    int idx = 1;
    while (true) {
      std::string& str = qry;
      bool ok = false;
      for (auto ptr : itm->ptr) {
        if (!ptr->is_str && ptr->val == str) {
          itm = ptr;
          ok = true;
          break;
        }
      }
      if (!ok) {
        std::cout << "no such property" << std::endl;
        return;
      }
      if (idx == qry.size()) {
        item* obj = itm->ptr.front();
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
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);
  solve();
  return 0;
}