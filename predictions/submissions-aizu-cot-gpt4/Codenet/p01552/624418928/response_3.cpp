#include <iostream>
#include <vector>
#include <cassert>
#include <memory>

typedef long long int ll;
typedef std::pair<int, int> pii;
const int inf = 1 << 30;
const ll infll = 1LL << 62;
const double eps = 1e-9;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct Item {
    std::vector<std::shared_ptr<Item>> ptr;
    std::string val;
    bool is_str;
};

bool isalphabet(char ch) { return 'a' <= ch and ch <= 'z'; }
bool is_indent(std::string &s, int i, int n) {
  for (int j = 0; j < n; ++j) {
    if (s[i + j] != ' ') {
      return false;
    }
  }
  return true;
}

std::string key(std::string &s, int &i) {
    int start = i;
    while (isalphabet(s[i]) or isdigit(s[i])) {
        ++i;
    }
    return s.substr(start, i - start);
}

void solve() {
  std::string qry, yaml_str;
  std::cin >> qry;
  std::cin.ignore();
  {
    std::string buf;
    while (getline(std::cin, buf)) {
      yaml_str += buf;
      yaml_str += '\n';
    }
  }
  Item root;
  root.val = "root";
  {
    int idx = 0;
    yaml(yaml_str, idx, root);
  }
  {
    Item *itm = &root;
    int idx = 1;
    while (true) {
      std::string str = string_(qry, idx);
      bool ok = false;
      for(int i = 0; i < itm->ptr.size(); i++) 
          if (!itm->ptr[i]->is_str and itm->ptr[i]->val == str) {
            itm = itm->ptr[i].get();
            ok = true;
            break;
          }
      if (!ok) {
        std::cout << "no such property" << std::endl;
        return;
      }
      if (idx == qry.size()) {
        Item *obj = itm->ptr.front().get();
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